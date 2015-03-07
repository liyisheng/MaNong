/*************************************************************************
    > File Name: ftp_server.c
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Tue 03 Mar 2015 11:24:03 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>

#define SER_IP "192.168.101.129"
#define SER_PORT 1234

int recv_buf(int sfd, char *buf, int len);
int send_buf(int sfd, char *buf, int len);
void child_main(int cfd);
int main()
{
	chdir(getenv("HOME"));

	int sfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sfd == -1)
	{
		perror("socket");
		exit(-1);
	}

	struct sockaddr_in ser_addr;
	memset(&ser_addr, 0, sizeof(ser_addr));
	ser_addr.sin_family = AF_INET;
	ser_addr.sin_port = htons(SER_PORT);
	ser_addr.sin_addr.s_addr = inet_addr(SER_IP);

	if(-1 == bind(sfd, (struct sockaddr*)&ser_addr, sizeof(ser_addr)))
	{
		perror("bind");
		close(sfd);
		exit(-1);
	}


	if( -1 == listen(sfd, 10))
	{
		perror("listen");
		close(sfd);
		exit(-1);
	}

	while(1)
	{
		struct sockaddr_in client_addr;
		memset(&client_addr, 0, sizeof(client_addr));
		int addrlen = sizeof(client_addr);
		int cfd = accept(sfd, (struct sockaddr*)&client_addr, &addrlen);
		if(cfd == -1)
		{
			perror("accept");
			close(sfd);
			exit(-1);
		}
		printf("%s %d success connect\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

		if(fork() == 0) 
		{
			close(sfd);
			child_main(cfd);
			close(cfd);
			exit(1);
		}
		close(cfd);	
	}
	return 0;	
}

int recv_buf(int sfd, char *buf, int len)
{
	int recv_sum = 0;
	int recv_ret;
	while(recv_sum < len)
	{
		recv_ret = recv(sfd, buf + recv_sum, len - recv_sum, 0);
		recv_sum += recv_ret;
	}
	return recv_sum;
}

int send_buf(int sfd, char *buf, int len)
{
	int send_sum = 0;
	int send_ret;
	while(send_sum < len)
	{
		send_ret = send(sfd, buf + send_sum, len - send_sum, 0);
		send_sum += send_ret;
	}

	return send_sum;
}


void child_main(int cfd)
{
	int recv_len;
	int send_len;
	char msg[1024] = ""; 
	char command[10] = ""; //ls, pwd, gets, puts, cd, remove
	char buffer[BUFSIZ + 1];
	while(1)
	{
		memset(msg, 0, 1024);
		memset(command, 0, 1024);
		recv_buf(cfd, (char*)&recv_len, 4);
		recv_buf(cfd, msg, recv_len);
		sscanf(msg, "%s", command);
		if(strcmp(command, "bye") == 0)
			break;
		if(strcmp(command, "ls") == 0)
		{
			FILE *read_fp;	
			int chars_read;
			memset(buffer, 0, sizeof(buffer));
			strcat(msg, " 2>&1");
			read_fp = popen(msg, "r");
			if(read_fp != NULL)
			{
				chars_read = fread(buffer, sizeof(char), BUFSIZ, read_fp);
				if(chars_read > 0)
				{
					send_buf(cfd, (char*)&chars_read, 4);
					send_buf(cfd, buffer, chars_read);
				}
			}
			pclose(read_fp);
		}else if(strcmp(command, "pwd") == 0)
		{
			memset(buffer, 0, sizeof(buffer));
			if(getcwd(buffer, 1024) != NULL)
			{
				send_len = strlen(buffer) + 1;
				buffer[send_len] = '\0';
				buffer[send_len - 1] = '\n';
				send_buf(cfd, (char*)&send_len, 4);
				send_buf(cfd, buffer, send_len);
			}
		}else if(strcmp(command, "cd") == 0)
		{
			char *file_path = msg;
			file_path = file_path + 2;
			while(isblank(*file_path) && *file_path != '\0')
				file_path++;
			if(chdir(file_path) == -1)	
			{
				strcpy(buffer, strerror(errno));
				strcat(buffer, "\n");
			}
			else
				strcpy(buffer, "ok\n");
			send_len = strlen(buffer);
			send_buf(cfd, (char*)&send_len, 4);
			send_buf(cfd, buffer, send_len);

		}
		else{
			strcpy(buffer, "error command!\n");
			send_len = strlen(buffer);
			send_buf(cfd, (char*)&send_len, 4);
			send_buf(cfd, buffer, send_len);
		}
	}
}

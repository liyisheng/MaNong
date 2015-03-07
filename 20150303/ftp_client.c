/*************************************************************************
    > File Name: ftp_client.c
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Tue 03 Mar 2015 02:07:10 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<signal.h>

#define SER_IP "192.168.101.129"
#define SER_PORT 1234
int recv_buf(int sfd, char *buf, int len);
int send_buf(int sfd, char *buf, int len);
int main(int argc, char* argv[])
{
	int cfd;
	int send_len, recv_len;
	char msg[1024];

	cfd = socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in seraddr;
	memset(&seraddr, 0, sizeof(seraddr));
	seraddr.sin_family = AF_INET;
	seraddr.sin_port = htons(SER_PORT);
	seraddr.sin_addr.s_addr = inet_addr(SER_IP);

	if( -1 == connect(cfd, (struct sockaddr*)&seraddr, 16) )
	{
		perror("connet");
		close(cfd);
		exit(-1);
	}
	while(1)
	{
		fflush(stdin);
		memset(msg, 0, 1024);
		fgets(msg, 1024, stdin);
		send_len = strlen(msg) - 1;
		msg[send_len] = '\0';
		if(strcmp(msg, "bye") == 0)
			break;
		send_buf(cfd, (char *)&send_len, 4);
		send_buf(cfd, msg, send_len);

		memset(msg, 0, 1024);
		recv_buf(cfd, (char*)&recv_len, 4);
		recv_buf(cfd, msg, recv_len);
		printf("%s", msg);
	}
	return  0;
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


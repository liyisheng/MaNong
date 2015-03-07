/*************************************************************************
  > File Name: client.c
  > Author: Comst
  > Mail:750145240@qq.com 
  > Created Time: Mon 09 Feb 2015 11:08:54 PM CST
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
#define SER_IP "120.24.236.135"
#define SER_PORT 1234
int send_buf(int sfd, char* buf, int len ) ;
int recv_buf(int sfd, char* buf, int len ) ;
int main(int argc, char* argv[])//src  dest
{
	int fd_client ;
	int send_len, recv_len ;
	char msg[1024] ;
	fd_client = socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in seraddr ;
	memset(&seraddr, 0, sizeof(seraddr));
	seraddr.sin_family = AF_INET ;
	seraddr.sin_port = htons(SER_PORT);
	seraddr.sin_addr.s_addr = inet_addr(SER_IP);
	if(-1 == connect(fd_client, (struct sockaddr*)&seraddr, 16))
	{
		perror("connect");
		close(fd_client);
		exit(1);
	}

	memset(msg, 0, 1024) ;
	strcpy(msg, argv[1]);
	send_len = strlen(msg);
	send_buf(fd_client, (char*)&send_len, 4);
	send_buf(fd_client, (char*)msg, send_len);

	memset(msg, 0, 1024);
	recv_buf(fd_client, (char*)&recv_len, 4);
	recv_buf(fd_client, msg, recv_len);
	if(strcmp(msg, "ok") == 0)
	{
		printf("begin recv file!\n");
	}else 
	{
		printf("error file addr! \n");
		close(fd_client);
		return 0 ;
	}
	int fd_file = open(argv[2], O_WRONLY | O_CREAT, 0666 );
	if(fd_file == -1)
	{
		perror("open");
		close(fd_client);
		exit(1);
	}
	int recv_sum  = 0 ;
	while(1)
	{
		memset(msg, 0, 1024);
		recv_buf(fd_client, (char*)&recv_len, 4);
		if(recv_len == 0)
		{
			close(fd_file);
			break ;
		}
		recv_sum += recv_buf(fd_client, msg, recv_len);
		write(fd_file, msg, recv_len);
		system("clear") ;
		printf("downloading... %.2fkbs\n",(double)recv_sum / 1024 );
	}
	




	return 0 ;
}
int send_buf(int sfd, char* buf, int len )
{
	int send_sum = 0 ;
	int send_ret ;
	while(send_sum < len)
	{
		send_ret = send(sfd, buf + send_sum, len - send_sum, 0);
		send_sum += send_ret ;
	}
	return send_sum ;
}
int recv_buf(int sfd, char* buf, int len )
{
	int recv_sum = 0 ;
	int recv_ret ;
	while(recv_sum < len)
	{
		recv_ret = recv(sfd, buf + recv_sum, len - recv_sum, 0);
		recv_sum += recv_ret ;
	}
	return recv_sum ;
}



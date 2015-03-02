/*************************************************************************
	> File Name: server.c
	> Author: Comst
	> Mail:750145240@qq.com 
	> Created Time: Sun 08 Feb 2015 06:28:54 PM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include <netinet/in.h>
#include<arpa/inet.h>

#define SER_IP "192.168.1.100"
#define SER_PORT 2015
int recv_buf(int sfd, char* buf, int len);
int main(int argc, char* argv[])
{
	//socket
	int fd_listen = socket(AF_INET, SOCK_STREAM, 0);
	if(fd_listen == -1)
	{
		perror("socket");
		exit(1);
	}
	//bind
	struct sockaddr_in seraddr ;
	memset(&seraddr, 0, sizeof(seraddr));
	seraddr.sin_family = AF_INET ;
	seraddr.sin_port = htons(SER_PORT);
	seraddr.sin_addr.s_addr  = inet_addr(SER_IP);
	if(-1 ==bind(fd_listen, (const struct sockaddr*)&seraddr, sizeof(seraddr)) )
	{
		perror("bind");
		exit(1);
	}
	//listen
	if(-1 == listen(fd_listen, 5))
	{
		perror("listen");
		exit(1);
	}
	//accept
	struct sockaddr_in clientaddr ;
	socklen_t len = sizeof(clientaddr) ;
	memset(&clientaddr, 0, sizeof(clientaddr));

	int fd_client = accept(fd_listen,(struct sockaddr*)&clientaddr, &len );
	if(fd_client == -1)
	{
		perror("accept");
		exit(1);
	}

	printf("%s: %d connect!\n", inet_ntoa(clientaddr.sin_addr), ntohs(clientaddr.sin_port));

	//recv 
	char buf[1024] = "" ;
	int* parr = (int* )calloc(1024 * 100000, sizeof(int));
//	int recvn = recv(fd_client, parr, 1024 * 40, 0);
//	printf("recv from client: %s\n", recv_buf);
	int recvn = recv_buf(fd_client, (char*)parr, 1024* 400000);
	printf("recvn: %d\n", recvn);

	//send
	memset(buf, 0, 1024);
	strcpy(buf, "!!!!!!!\n");
	send(fd_client, buf, strlen(buf), 0);	
	while(1);
	close(fd_listen);
	close(fd_client);



}
int recv_buf(int sfd, char* buf, int len)
{
	int recv_sum = 0 ;
	int recv_ret ;
	int recv_cnt = 0 ;
	while(recv_sum < len)
	{
		recv_ret = recv(sfd, buf + recv_sum, len - recv_sum, 0);
		recv_cnt ++ ;

		recv_sum += recv_ret ;
	}
	printf("recv_cnt: %d\n", recv_cnt);
	return recv_sum ;

}

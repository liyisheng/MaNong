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
#define SER_PORT 1234
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
	while(1);
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
	char recv_buf[1024] = "" ;
	recv(fd_client, recv_buf, 1024, 0);
	printf("recv from client: %s\n", recv_buf);

	//send
	memset(recv_buf, 0, 1024);
	strcpy(recv_buf, "!!!!!!!\n");
	send(fd_client, recv_buf, strlen(recv_buf), 0);
	
	close(fd_listen);
	close(fd_client);



}

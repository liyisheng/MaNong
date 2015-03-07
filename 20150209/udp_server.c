/*************************************************************************
	> File Name: udp_server.c
	> Author: Comst
	> Mail:750145240@qq.com 
	> Created Time: Mon 09 Feb 2015 04:46:56 PM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#define SER_IP "120.24.236.135"
#define SER_PORT  1234
int main(int argc, char* argv[])
{
	int fd_server ;
	fd_server = socket(AF_INET, SOCK_DGRAM, 0);
	if(fd_server == -1)
	{
		perror("socket");
		exit(1);
	}
	struct sockaddr_in seraddr, clientaddr  ;
	socklen_t sock_len ;
	memset(&seraddr, 0, sizeof(seraddr));
	seraddr.sin_family = AF_INET ;
	seraddr.sin_port = htons(SER_PORT);
	seraddr.sin_addr.s_addr = inet_addr(SER_IP);
	if(-1 == bind(fd_server, (struct sockaddr*)&seraddr, 16))
	{
		perror("bind");
		close(fd_server);
		exit(1);
	}
	memset(&clientaddr, 0, sizeof(clientaddr));
	sock_len = sizeof(clientaddr) ;
	char msg[1024] = "" ;
	recvfrom(fd_server, msg, 1024,0, (struct sockaddr*)&clientaddr, &sock_len );
	printf("%s:%d msg: %s\n",inet_ntoa(clientaddr.sin_addr), ntohs(clientaddr.sin_port), msg );
	printf("Y|N?\n");
	memset(msg, 0, 1024);
	fgets(msg, 1024, stdin) ;
	sendto(fd_server, msg, strlen(msg), 0, (struct sockaddr*)&clientaddr, sizeof(clientaddr));
	if(msg[0] == 'Y')
	{
		while(memset(msg, 0, 1024),recvfrom(fd_server, msg, 1024, 0, NULL, NULL) )
		{
			printf("from %s: %d:\n\t\t%s\n",inet_ntoa(clientaddr.sin_addr), ntohs(clientaddr.sin_port), msg );
			if(strcmp("over", msg) == 0)
			{
				close(fd_server);
				break ;
			}

			memset(msg, 0, 1024);
			fgets(msg, 1024, stdin) ;
			sendto(fd_server, msg, strlen(msg), 0, (struct sockaddr*)&clientaddr, sizeof(clientaddr));


		}
	
	}else 
	{
		close(fd_server);
	}



	return 0 ;
}

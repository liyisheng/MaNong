/*************************************************************************
  > File Name: client.c
  > Author: Comst
  > Mail:750145240@qq.com 
  > Created Time: Tue 10 Feb 2015 01:10:13 AM CST
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

	int fd_client ;
	fd_client = socket(AF_INET, SOCK_DGRAM, 0);
	if(fd_client == -1)
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

	char msg[1024] = "chat?\n" ;
	sendto(fd_client, msg, strlen(msg), 0, (struct sockaddr*)&seraddr, 16);
	memset(msg, 0, 1024);
	recvfrom(fd_client, msg, 1024, 0, NULL,  NULL);
	if(msg[0] == 'Y')
	{
		while(memset(msg, 0, 1024), fgets(msg, 1024, stdin) != NULL)
		{
			
			sendto(fd_client, msg, strlen(msg), 0, (struct sockaddr*)&seraddr, 16);

			memset(msg, 0, 1024);
			recvfrom(fd_client, msg, 1024, 0, NULL,  NULL);
			printf("from %s: %d:\n\t\t%s\n",inet_ntoa(seraddr.sin_addr), ntohs(seraddr.sin_port), msg ) ;
		}
			memset(msg, 0, 1024);
			strcpy(msg, "over");
			sendto(fd_client, msg, strlen(msg), 0, (struct sockaddr*)&seraddr, 16);
			close(fd_client);

	}else 
	{
		close(fd_client);
	}

}

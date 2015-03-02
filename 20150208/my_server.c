/*************************************************************************
    > File Name: my_server.c
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Mon 02 Mar 2015 12:37:39 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>



#define SER_IP "192.168.101.129"
#define SER_PORT 1234


int main(int argc, char *argv[])
{
	//socket-->bind-->listen-->accept-->recv/recvfrom-->send/sendto-->close
	int nRet;
	int fd = socket(AF_INET, SOCK_STREAM, 0);
	if(fd == -1)
	{
		perror("socket");
		exit(-1);
	}

	struct sockaddr_in ser_addr;
	memset(&ser_addr, 0, sizeof(ser_addr));
	ser_addr.sin_family = AF_INET; //地址族
	ser_addr.sin_port = htons(SER_PORT);
	ser_addr.sin_addr.s_addr = inet_addr(SER_IP);

	nRet = bind(fd, (const struct sockaddr*)&ser_addr, sizeof(ser_addr));
	if(nRet == -1)
	{
		perror("bind");
		close(fd);
		exit(-1);
	}

	nRet = listen(fd, 10);
	if(nRet == -1)
	{
		perror("listen");
		close(fd);
		exit(-1);
	}

	struct sockaddr_in cli_addr;
	memset(&cli_addr, 0, sizeof(cli_addr));

	int addrlen = sizeof(cli_addr);

	int new_fd = accept(fd, (struct sockaddr*)&cli_addr, &addrlen);
	if(new_fd == -1)
	{
		perror("accept");
		close(fd);
		exit(-1);
	}
	printf("%s: %d success connect\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

	char buf[1024] = {0};
	nRet = recv(new_fd, buf, sizeof(buf), 0);
	if(nRet == -1)
	{
		perror("recv");
		close(new_fd);
		exit(-1);
	}
	printf("recv from client: %s\n", buf);

	memset(buf, 0, 1024);
	strcpy(buf, "!!!!!!\n");

	nRet = send(new_fd, buf, strlen(buf), 0);
	if(nRet == -1)
	{
		perror("send");
		close(new_fd);
		exit(-1);
	}

	close(new_fd);
	close(fd);

	return 0;

}

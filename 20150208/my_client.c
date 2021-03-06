/*************************************************************************
    > File Name: my_client.c
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Mon 02 Mar 2015 02:52:54 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#define SER_IP "192.168.101.129"
#define SER_PORT 1234 

int send_buf(int sfd, char *buf, int len);


int main(int argc, char *argv[])
{
	int nRet;
	int fd_client = socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in seraddr;
	memset(&seraddr, 0, sizeof(seraddr));
	seraddr.sin_family = AF_INET;
	seraddr.sin_port = htons(SER_PORT);
	seraddr.sin_addr.s_addr = inet_addr(SER_IP);
	nRet = connect(fd_client, (struct sockaddr*)&seraddr, sizeof(seraddr));
	if(nRet == -1)
	{
		perror("connet");
		close(fd_client);
		exit(-1);
	}

	char p[1024] = {0};
	scanf("%s", p);
	//send(fd_client, p, strlen(p), 0);
	int sendn = send_buf(fd_client, p, 1024);	
	printf("sendn :%d\n", sendn);

char recv_buf[1024] = "";
	recv(fd_client, recv_buf, 1024, 0);
	printf("from server: %s\n", recv_buf);
	close(fd_client);
	return 0;
	
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

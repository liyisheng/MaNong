/*************************************************************************
	> File Name: cl2.c
	> Author: Comst
	> Mail:750145240@qq.com 
	> Created Time: Wed 28 Jan 2015 08:22:10 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc, char* argv[])//cl2 ->cl1 cl1 ->cl2 
{
	int fd_send = open(argv[1], O_WRONLY);
	int fd_recv = open(argv[2], O_RDONLY);
	if(fd_send == -1 || fd_recv == -1) 
	{
		perror("open");
		exit(1);
	}
	printf("OK!\n");
	char buf[1024] ;
	while(memset(buf, 0, 1024),read(fd_recv, buf, 1024) != 0)
	{
		printf("from cl1: %s\n", buf);
		memset(buf, 0, 1024);
		read(0, buf, 1024);
		write(fd_send, buf, strlen(buf));
	}
	printf("cl1 exit!\n");
	close(fd_send);
	close(fd_recv);
	return 0 ;
}




/*************************************************************************
	> File Name: cl1.c
	> Author: Comst
	> Mail:750145240@qq.com 
	> Created Time: Wed 28 Jan 2015 08:22:04 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc, char* argv[])//cl1->cl2  cl2->cl1 
{
	int fd_recv = open(argv[2], O_RDONLY);
	int fd_send = open(argv[1], O_WRONLY);
	if(fd_send == -1 || fd_recv == -1)
	{
		perror("open");
		exit(1);
	}
	printf("OK!\n");
	char buf[1024] ;
	while(memset(buf, 0, 1024), read(0, buf, 1024) != 0)
	{
		write(fd_send, buf, strlen(buf));
		memset(buf, 0, 1024);
		read(fd_recv, buf, 1024);
		printf("from cl2: %s\n", buf);
	}
	close(fd_send);
	close(fd_recv);
	return 0 ;
}



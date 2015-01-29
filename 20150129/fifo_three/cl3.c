/*************************************************************************
    > File Name: cl3.c
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Thu 29 Jan 2015 09:43:15 AM CST
 ************************************************************************/
#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
int main(int argc, char *argv[])
{
	int fd1 = open("fifo23", O_RDONLY);
	int fd2 = open(argv[2],O_WRONLY);
	if(fd1 == -1)
		perror("open"), exit(1);
	printf("OK!\n");
	char buf[1024];
	while(memset(buf, 0, 1024), read(fd1, buf, 1024) != 0 )
	{
		write(1, buf, strlen(buf));
		write(fd2, buf,strlen(buf));
	}

}



 

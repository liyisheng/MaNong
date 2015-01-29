/*************************************************************************
    > File Name: cl1.c
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Thu 29 Jan 2015 09:42:35 AM CST
 ************************************************************************/

#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
int main(int argc, char *argv[])
{
	int fd12, fd13;
	char buf[1024];
	fd12 = open("fifo12",O_WRONLY);
	fd13 = open("fofo13",O_WRONLY);
	if(fd12 == -1 || fd23 == -1)
		perror("open"), exit(1);
	printf("SEND!\n");
	while(memset(buf, 0, 1024), read(0, buf, 1024) != 0 )
	{
		write(fd1, buf, strlen(buf));
		write(fd2, buf, strlen(buf));
		close(fd12);
		close(fd13);
	}

	
}


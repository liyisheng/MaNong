/*************************************************************************
    > File Name: cl1.c
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Thu 29 Jan 2015 09:42:35 AM CST
 ************************************************************************/

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<sys/select.h>
#include<sys/time.h>
#include<string.h>

int main(int argc, char *argv[])
{
	fd_set rdfs;
	struct timeval tv;
	int retval;
	int fd12, fd13;
	char buf[1024];
	fd12 = open("fifo12",O_RDONLY);
	fd13 = open("fifo13",O_RDONLY);
	if(fd12 == -1 || fd13 == -1)
		perror("open"), exit(1);
	
	while(1)
	{
		FD_ZERO(&rdfs);
		FD_SET(fd12, &rdfs);
		FD_SET(fd13, &rdfs);
		retval = select(5, &rdfs, NULL, NULL, NULL);
		if(-1 == retval)
		{
			perror("select()");
			break;
		}
		if(FD_ISSET(fd12, &rdfs))
		{
			memset(buf, 0, sizeof(buf));
			read(fd12, buf, sizeof(buf));
			printf("%s", buf);
		}else
		{
			memset(buf, 0, sizeof(buf));
			read(fd13, buf, sizeof(buf));
			printf("%s", buf);
		}
	}
	close(fd12);
	close(fd13);
}

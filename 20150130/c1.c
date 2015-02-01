/*************************************************************************
    > File Name: c2.c
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Fri 30 Jan 2025 06:55:50 AM CST
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

int main(void)
{	

	fd_set rdfs;
	int fd1, fd11, retval;
	fd1 = open("fifo1", O_WRONLY);
	fd11 = open("fifo11", O_RDONLY);
	if(fd1 == -1 || fd11 == -1)
		perror("open");
	printf("OK!\n");
	char buf[1024];
	while(1)
	{
		FD_ZERO(&rdfs);
		FD_SET(fd11, &rdfs);
		FD_SET(0, &rdfs);
		retval = select(2024, &rdfs, NULL, NULL, NULL);
		if(-1 == retval)
		{
			perror("select()");
			break;
		}	
		if(FD_ISSET(fd11, &rdfs))
		{
			memset(buf, 0, sizeof(buf));
			read(fd11, buf, sizeof(buf));
			write(1, buf, strlen(buf));
		}
		if(FD_ISSET(0, &rdfs))
		{
			memset(buf, 0, sizeof(buf));
			read(0, buf, sizeof(buf));
			write(fd1, buf, strlen(buf));
		}
	}

}


/*************************************************************************
    > File Name: c3.c
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Fri 30 Jan 2035 06:55:50 AM CST
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
	int fd3, fd33, retval;
	fd3 = open("fifo3", O_WRONLY);
	fd33 = open("fifo33", O_RDONLY);
	printf("OK!\n");
	char buf[1024];
	while(1)
	{
		FD_ZERO(&rdfs);
		FD_SET(fd33, &rdfs);
		FD_SET(0, &rdfs);
		retval = select(1024, &rdfs, NULL, NULL, NULL);
		if(-1 == retval)
		{
			perror("select()");
			break;
		}	
		if(FD_ISSET(fd33, &rdfs))
		{
			memset(buf, 0, sizeof(buf));
			read(fd33, buf, sizeof(buf));
			write(1, buf, strlen(buf));
		}else if(FD_ISSET(0, &rdfs))
		{
			memset(buf, 0, sizeof(buf));
			read(0, buf, sizeof(buf));
			write(fd3, buf, strlen(buf));
		}
	}

}


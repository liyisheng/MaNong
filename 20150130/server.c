/*************************************************************************
    > File Name: server.c
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Fri 30 Jan 2015 06:06:32 AM CST
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
	int retval, fd1, fd2, fd3, fd11, fd22, fd33;
	fd_set rdfs;		
	fd1 = open("fifo1", O_RDONLY);
	fd11 = open("fifo11", O_WRONLY);
	if(fd1 == -1 || fd11 == -1)
	{
		perror("open");
		exit(1);
	}
	printf("1 OK\n");
	fd2 = open("fifo2", O_RDONLY);
	fd22 = open("fifo22", O_WRONLY);
	if(fd2 == -1 || fd22 == -1)
	{
		perror("open");
		exit(1);
	}
	printf("2 OK!\n");

	fd3 = open("fifo3", O_RDONLY);
	fd33 = open("fifo33", O_WRONLY);
	if(fd3 == -1 || fd33 == -1)
	{
		perror("open");
		exit(1);
	}
	printf("3 OK\n");

	char buf[1024];
	while(1)	
	{
		FD_ZERO(&rdfs);
		FD_SET(fd1, &rdfs);
		FD_SET(fd2, &rdfs);
		FD_SET(fd3, &rdfs);
		retval = select(1024, &rdfs, NULL, NULL, NULL);
		if(-1 == retval)
		{
			perror("select()");
			break;
		}

		if(FD_ISSET(fd1, &rdfs))
		{
			memset(buf, 0, sizeof(buf));
			read(fd1, buf, sizeof(buf));
			printf("%s", buf);
			write(fd22, buf, strlen(buf));
			write(fd33, buf, strlen(buf));
		}else if(FD_ISSET(fd2, &rdfs))
		{
			memset(buf, 0, sizeof(buf));
			read(fd2, buf, sizeof(buf));
			printf("%s", buf);
			write(fd11, buf, strlen(buf));
			write(fd33, buf, strlen(buf));
		}else if(FD_ISSET(fd3, &rdfs))
		{
			memset(buf, 0, sizeof(buf));
			read(fd3, buf, sizeof(buf));
			printf("%s", buf);
			write(fd11, buf, strlen(buf));
			write(fd22, buf, strlen(buf));
		}
	}

	return 0;
}
	






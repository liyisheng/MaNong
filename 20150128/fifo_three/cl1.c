/*************************************************************************
    > File Name: cl1.c
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Thu 29 Jan 2015 09:42:35 AM CST
 ************************************************************************/

#include<stdio.h>
int main()
{
	int fd1 = open(argv[1], O_RDONLY);
	int fd2 = open(argv[2],O_WRONLY);
	if(fd1 == -1 || fd2 == -1)
		perror("open"), exit(1);
	printf("OK!\n");
	char buf[1024];
	while(memset(buf, 0, 1024), read(0, buf, 1024)! = 0 )
	{
		write(fd2, buf, strlen(buf));
		memset(buf, 0, 1024);
		read(fd1, buf, 1024);
	}

}


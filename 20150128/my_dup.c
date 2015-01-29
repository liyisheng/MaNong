/*************************************************************************
  > File Name: my_dup.c
  > Author: Comst
  > Mail:750145240@qq.com 
  > Created Time: Wed 28 Jan 2015 03:01:40 PM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc, char* argv[])
{
	char* p = "hello world! \n" ;
	int fd = open(argv[1], O_WRONLY | O_CREAT, 0666);
	dup2(fd, 1);
	
	close(fd);
	read(0);
	write(1 , p, strlen(p));
	return 0 ;
}

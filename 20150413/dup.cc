/*************************************************************************
    > File Name: dup.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Mon 13 Apr 2015 01:44:23 AM PDT
 ************************************************************************/
/*
 * dup实现重定向
 * */
#include<iostream>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
using namespace std;

int main(int argc, char *argv[])
{
	int fd = open("a.txt", O_WRONLY | O_CREAT | O_TRUNC);
	if( -1 == fd)
	{
		exit(-1);
	}
//	printf("\n"); /*必不可少*/  //????
	close(1);
	int fd2 = dup(fd);
	close(fd);
	printf("hello world!\n");
	fflush(stdout);
	close(fd2);
	return 0;
}

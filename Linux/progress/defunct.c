/*************************************************************************
    > File Name: defunct.c
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Thu 16 Apr 2015 01:02:37 AM PDT
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
	pid_t pid = fork();
	if(pid ==0)
	{
		exit(10);
	}else
	{
		wait(NULL);
		sleep(10);
	}
	return 0;
}

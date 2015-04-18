/*************************************************************************
    > File Name: defunct.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Thu 16 Apr 2015 12:57:35 AM PDT
 ************************************************************************/

#include<iostream>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
using namespace std;

int main(int argc, char *argv[])
{
	pid_t pid = fork();
	if(pid == 0)
	{
		exit(10);
	}else
	{
		wait(NULL);
		sleep(10);
	}
	return 0;
}

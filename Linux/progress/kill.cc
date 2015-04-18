/*************************************************************************
    > File Name: kill.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Fri 17 Apr 2015 03:01:24 AM PDT
 ************************************************************************/

#include<iostream>
#include<sys/types.h>
#include<unistd.h>
#include<signal.h>
#include<stdio.h>
using namespace std;

int main(int argc, char *argv[])
{
	while(1)
	{
		if(getchar() == EOF)
			kill(getpid(), SIGQUIT);
	}
	return 0;
}

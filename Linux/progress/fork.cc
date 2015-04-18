/*************************************************************************
    > File Name: fork.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Tue 14 Apr 2015 01:02:21 AM PDT
 ************************************************************************/

#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
using namespace std;

int main(int argc, char *argv[])
{
	cout << "Parent process id :" << getpid() << endl;
	pid_t iRet = fork();
	if(iRet < 0)
	{
		cout << "fail!"<< endl;
	}else if(iRet == 0)
	{
		cout << "child id :" << getpid() << "  ppid:" << getppid() <<endl;
	}else
	{
//		sleep(2);
		cout << "child id iRet:"<< iRet << endl;
	}
	return 0;
}

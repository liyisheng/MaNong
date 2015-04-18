/*************************************************************************
    > File Name: dup2.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Mon 13 Apr 2015 02:00:11 AM PDT
 ************************************************************************/

#include<stdio.h>
#include<iostream>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
using namespace std;

int main(int argc, char *argv[])
{
	char buf[128] = {0};
	int fda = open("./dup2.cc", O_RDONLY);
	int fdb = open("./dup.cc", O_RDONLY);
	int fdbb = dup(fdb);
	int fda2 = dup2(fda, fdb);
	cout << fda << fdb << fdbb << fda2 << endl;
	read(fdb, buf, sizeof(buf) - 1);
	printf("result:%s\n", buf);
	close(fda);
	close(fdb);
	close(fdbb);
	close(fda2);
	return 0;
}

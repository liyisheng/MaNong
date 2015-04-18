/*************************************************************************
    > File Name: read_write.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Mon 13 Apr 2015 01:23:11 AM PDT
 ************************************************************************/

#include<iostream>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
using namespace std;
int main(int argc, char *argv[])
{
	char buf[1024] = {0};
	int f1 = open("./read_write.cc", O_RDONLY);
	int f2 = open("./a.txt",O_WRONLY | O_CREAT, 0755);

	if(-1 == f1 || -1 == f2)
	{
		perror("open failed.\n");
		exit(-1);
	}
	int fr = 0;
	while((fr = read(f1, buf, sizeof(buf))) > 0)
	{
		int fw = write(f2, buf, fr);
		if(-1 == fw)
		{
			perror("write failed!");
			exit(-1);
		}
	}
	close(f1);
	close(f2);
	return 0;
}

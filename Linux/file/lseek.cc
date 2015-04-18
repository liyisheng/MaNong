/*************************************************************************
    > File Name: lseek.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Mon 13 Apr 2015 01:09:41 AM PDT
 ************************************************************************/

#include<iostream>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
using namespace std;

int main(int argc, char *argv[])
{
	int fd = open("c.txt", O_WRONLY | O_CREAT);
	lseek(fd, 1024, SEEK_SET);
	write(fd, "a", 1);
	close(fd);
	return 0;
}

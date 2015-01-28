/*************************************************************************
    > File Name: copy_system.c
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Mon 26 Jan 2015 04:02:02 PM CST
 ************************************************************************/
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>


int main()
{
	char c;
	int in, out;
	in = open("1.txt", O_RDONLY);
	out = open("file.out", O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);
	while(read(in, &c, 1))
		write(out, &c, 1);
	exit(0);
}

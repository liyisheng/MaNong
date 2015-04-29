/*************************************************************************
    > File Name: lock1.c
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: 2015年04月29日 星期三 16时09分34秒
 ************************************************************************/

#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<stdio.h>
#include<stdlib.h>


int main()
{
	int file_desc;
	int save_errno;

	file_desc = open("/tmp/LCK.test", O_RDWR | O_CREAT | O_EXCL , 0444);

	if(file_desc == -1)
	{
		save_errno = errno;
		printf("Open failed with error %d\n", save_errno);
	}else
		printf("Open succeeded\n");

	exit(EXIT_SUCCESS);
}

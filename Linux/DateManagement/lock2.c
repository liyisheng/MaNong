/*************************************************************************
    > File Name: lock2.c
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: 2015年04月29日 星期三 16时12分19秒
 ************************************************************************/

#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<stdio.h>
#include<stdlib.h>

const char *lock_file = "/tmp/LCK.test2";

int main()
{
	int file_desc;
	int tries = 10;

	while(tries--)
	{
		file_desc = open(lock_file, O_RDWR | O_CREAT | O_EXCL, 0444 );
		if(file_desc == -1)
		{
			printf("%d -Lock already present\n",getpid());
			sleep(3);
		}else
		{
			printf("%d -I have exclusive access\n", getpid());
			sleep(1);
			close(file_desc);
			unlink(lock_file);
			sleep(2);
		}
	}
	exit(EXIT_SUCCESS);
}


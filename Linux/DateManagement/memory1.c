/*************************************************************************
    > File Name: memory1.c
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: 2015年04月29日 星期三 13时57分21秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define  A_MEGABYTE (1024 * 1024)

int main()
{
	char *some_memory;
	int megabyte = A_MEGABYTE;
	int exit_code = EXIT_FAILURE;

	some_memory = (char *)malloc(megabyte);
	if(some_memory  != NULL)
	{
		sprintf(some_memory, "Hello World!\n");
		printf("%s",  some_memory);
		exit_code = EXIT_SUCCESS;
	}

	exit(exit_code);
}

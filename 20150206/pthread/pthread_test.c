/*************************************************************************
    > File Name: pthread_test.c
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Fri 06 Feb 2015 09:46:30 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>


void * ThreadFunc(void *pArg)
{
	int i = 0;
	for(i = 0 ; i < 10; i++)
	{
		printf("I am child thread, arg is, %d\n", (int)pArg);
		sleep(1);
	}
	pthread_exit(NULL);
}


int main()
{
	pthread_t pthid;
	pthread_create(&pthid, NULL, ThreadFunc, (void *)123);

	int i = 0;
	for(i = 0; i < 10; i ++)
	{
		printf("I am main thread child thread id is: %x\n", pthid);
		sleep(1);
	}
	return 0;
}


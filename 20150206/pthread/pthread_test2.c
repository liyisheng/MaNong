/*************************************************************************
    > File Name: pthread_test2.c
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Mon 09 Feb 2015 03:18:24 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>


void *ThreadFun(void *arg)
{
	int i;
	int m = *(int *)arg;
	for(i = 0; i < 10; i++)
	{
		printf("I am a child thread, the arg is %d\n", m);
		sleep(1);
	}
	pthread_exit(arg);
}


int main()
{
	int i ,m = 123;
	int *pretval;
	pthread_t pthread_id;
	pthread_create(&pthread_id, NULL, ThreadFun, &m);

	for(i = 0; i < 5; i++)
	{
		printf("I am main thread, a child thread is : %d\n", pthread_id);
		sleep(1);
	}

	pthread_join(pthread_id, (void **)&pretval);
	printf("return value: %d\n", *pretval);
	return 0;
}

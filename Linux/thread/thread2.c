/*************************************************************************
    > File Name: thread1.c
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Sun 10 May 2015 02:38:12 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<pthread.h>

void *thread_function(void *arg);
char message[] = "Hello World";
int run_now  = 1;
int main()
{
	int res;
	pthread_t a_thread;
	void *thread_result;

	res = pthread_create(&a_thread, NULL, thread_function, (void*)message);
	if(res != 0)
	{
		perror("Thread creation failed");
		exit(EXIT_FAILURE);
	}
	
	int print_count1 = 0;
	while(print_count1++ < 20)
	{
		if(run_now == 1)
		{
			printf("1");
			run_now = 2;
		}else
			sleep(1);
	}
	

	printf("Waiting for thread to finish...\n");

	exit(EXIT_SUCCESS);

}

void *thread_function(void *arg)
{

	int print_count1 = 0;
	while(print_count1++ < 20)
	{
		if(run_now == 2)
		{
			printf("2");
			run_now = 1;
		}else
			sleep(1);
	}

}

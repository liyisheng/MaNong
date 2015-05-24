/*************************************************************************
    > File Name: thread5.c
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Tue 12 May 2015 08:24:27 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void *thread_function(void *arg);

char message[] = "Hello World!";
int thread_finished = 0;

int main()
{
	int res;	
	pthread_t a_thread;
	
	pthread_attr_t thread_attr;

	res = pthread_attr_init(&thread_attr);
	if(res != 0)
	{
		perror("Attibute creation failed");
		exit(EXIT_FAILURE);
	}

	res = pthread_attr_setdetachstate(&thread_attr, PTHREAD_CREATE_DETACHED);
	if(res != 0)
	{
		perror("Setting detached attirbute failed");
		exit(EXIT_FAILURE);
	}

	res = pthread_create(&a_thread, &thread_attr, thread_function, (void*)message);
	if(res != 0)
	{
		perror("Thread creation failed");
		exit(EXIT_FAILURE);
	}

	pthread_attr_destroy(&thread_attr);
	while(!thread_finished)
	{
		printf("Waiting for thread to say it's finished...\n");
		sleep(1);
	}
	printf("Other thread finished, bye!\n");
	exit(EXIT_SUCCESS);

}

void *thread_function(void *arg)
{
	printf("thread_fuction is running, Argument was %s\n", (char*)arg);
	sleep(4);
	printf("Second thread setting finished flag, and exiting now\n");
	thread_finished = 1;
	pthread_exit(NULL);
}


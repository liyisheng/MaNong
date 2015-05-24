/*************************************************************************
    > File Name: thread7.c
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Tue 12 May 2015 08:48:41 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void *thread_function(void *arg)
{
	int i, res;
	res = pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);

	res = pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, NULL);

	printf("thread_function is running \n");
	for(i = 0; i < 10; i++)
	{
		printf("Thread is still running (%d)...\n", i);
		sleep(1);
	}
	pthread_exit(0);

}

int main()
{
	int res;
	pthread_t a_thread;
	void *thread_result;

	res = pthread_create(&a_thread, NULL, thread_function, NULL);

	sleep(3);
	printf("Canceling thread..\n");
	res = pthread_cancel(a_thread);
	
	printf("Waiting for thread to finish...\n");
	res = pthread_join(a_thread, &thread_result);

	exit(EXIT_FAILURE);
}




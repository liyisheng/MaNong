/*************************************************************************
    > File Name: thread4.c
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Sun 10 May 2015 05:36:49 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<pthread.h>
#include<semaphore.h>


void *thread_function(void *arg);
pthread_mutex_t work_mutex;

#define WORK_SIZE 1024
char work_area[1024];
int time_to_exit = 0;


int main()
{
	int res;
	pthread_t a_thread;
	void *thread_result;

	res = pthread_mutex_init(&work_mutex, NULL);
	if(res != 0)
	{
		perror("Mutex initialization failed");
		exit(EXIT_FAILURE);
	}

	res = pthread_create(&a_thread, NULL, thread_function, NULL);

	pthread_mutex_lock(&work_mutex);
	printf("Input some text. Enter 'end' to finish\n");
	while(!time_to_exit)
	{
		fgets(work_area, WORK_SIZE, stdin);
		pthread_mutex_unlock(&work_mutex);
		while(1)
		{
			pthread_mutex_lock(&work_mutex);
			if(work_area[0] != '\0')
			{
				pthread_mutex_unlock(&work_mutex);
				sleep(1);
			}else
				break;
		}
	}

	pthread_mutex_unlock(&work_mutex);
	printf("\nWaiting for thread to finish...\n");
	res = pthread_join(a_thread, &thread_result);

	printf("Thread joined\n");

	pthread_mutex_destroy(&work_mutex);
	exit(EXIT_SUCCESS);
}


void *thread_function(void *arg)
{
	sleep(1);
	pthread_mutex_lock(&work_mutex);
	while(strncmp("end", work_area, 3) != 0)
	{
		printf("You input %d characters\n", strlen(work_area) - 1);
		work_area[0] = '\0';
		pthread_mutex_unlock(&work_mutex);
		sleep(1);
		pthread_mutex_lock(&work_mutex);
		while(work_area[0] == '\0')
		{
			pthread_mutex_unlock(&work_mutex);
			sleep(1);
			pthread_mutex_lock(&work_mutex);
		}
	}
	time_to_exit = 1;
	work_area[0] = '\0';
	pthread_mutex_unlock(&work_mutex);
	pthread_exit(NULL);
	
}


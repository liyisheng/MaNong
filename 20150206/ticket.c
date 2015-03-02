/*************************************************************************
    > File Name: ticket.c
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Mon 23 Feb 2015 11:02:14 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>

pthread_mutex_t mutex;
pthread_cond_t cond_pro, cond_con;

void * handle(void *arg)
{
	int *pt = (int *)arg;
	int soldn = 0;
	int tmp;
	while(1)
	{
		pthread_mutex_lock(&mutex);
		while(*pt == 0)
		{
			printf("no tickets!\n");
			pthread_cond_signal(&cond_pro);
			pthread_cond_wait(&cond_con, &mutex);

		}
	}
}
 

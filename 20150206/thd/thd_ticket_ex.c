/*************************************************************************
    > File Name: thd_ticket_ex.c
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Mon 23 Feb 2015 11:58:15 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int ticketcount = 20;
pthread_mutex_t lock;


void *salewind1(void *args)
{
	while(1)
	{
		pthread_mutex_lock(&lock);
		if(ticketcount > 0)
		{
			printf("windows1 start sale ticket! the ticket is :%d\n", ticketcount);
			sleep(3);
			ticketcount--;
			printf("sale ticket finish!, the last ticket is:%d\n", ticketcount);
		}else
		{
			pthread_mutex_unlock(&lock);
			pthread_exit(NULL);
		}

		pthread_mutex_unlock(&lock);
		sleep(1);
	}
}

void *salewind2(void *args)
{
	while(1)
	{
		pthread_mutex_lock(&lock);
		if(ticketcount > 0)
		{
			printf("windows2 start sale ticket! the ticket is :%d\n", ticketcount);
			sleep(3);
			ticketcount--;
			printf("sale ticket finish!, the last ticket is:%d\n", ticketcount);
		}else
		{
			pthread_mutex_unlock(&lock);
			pthread_exit(NULL);
		}

		pthread_mutex_unlock(&lock);
		sleep(1);
	}
}

int 
main()
{
	pthread_t pthid1 = 0;
	pthread_t pthid2 = 0;
	pthread_mutex_init(&lock, NULL);

	pthread_create(&pthid1,NULL, salewind1,NULL);
	pthread_create(&pthid2,NULL, salewind2,NULL);

	pthread_join(pthid1,NULL);
	pthread_join(pthid2,NULL);

	pthread_mutex_destroy(&lock);

	return 0;
}

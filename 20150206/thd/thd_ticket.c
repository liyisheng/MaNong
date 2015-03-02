/*************************************************************************
  > File Name: thd_ticket.c
  > Author: Comst
  > Mail:750145240@qq.com 
  > Created Time: Fri 06 Feb 2015 05:01:46 PM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
pthread_mutex_t mutex ;
void* handle(void* arg)
{
	int* pt = (int*)arg ;
	int soldn = 0 ;
	int tmp ;
	while(1)
	{
		while(pthread_mutex_lock(&mutex), *pt == 0)
		{
			printf("no tickets!\n");
			pthread_mutex_unlock(&mutex);
			sleep(1);
		}
		tmp = *pt ;
		tmp -- ;
		*pt = tmp ;
		soldn ++ ;
		pthread_mutex_unlock(&mutex);
		sleep(1);

	}
	pthread_mutex_unlock(&mutex);
	pthread_exit((void*)soldn);
}

void* handle1(void* arg)
{
	int* pt = (int*)arg ;
	while(1)
	{
		while( pthread_mutex_lock(&mutex), *pt > 0)
		{
			pthread_mutex_unlock(&mutex);
			sleep(1);
		}

		*pt = rand() % 20 + 1 ;
		printf("new tickets: %d\n", *pt);
		pthread_mutex_unlock(&mutex);
	}

}
int main(int argc, char* argv[])// nthds tickets
{
	int nthds = atoi(argv[1]);
	int ntickets = atoi(argv[2]);
	int total  = ntickets;
	pthread_t thd_bak;
	pthread_mutex_init(&mutex, NULL);
	pthread_t* thd_arr = (pthread_t*)calloc(nthds, sizeof(pthread_t));
	int* thd_tickets = (int*)calloc(nthds, sizeof(int));
	int i ;
	for(i = 0; i < nthds; i ++)
	{
		pthread_create( thd_arr + i, NULL, handle, (void*)&ntickets );
	}

	pthread_create(&thd_bak, NULL, handle1, (void*)&ntickets );

	for(i = 0; i < nthds; i ++)
	{
		pthread_join(thd_arr[i], (void*)(thd_tickets + i));
	}
	int sum ;
	for(sum = 0, i = 0; i < nthds; i ++)
	{
		sum += thd_tickets[i] ;
	}

	printf("sold: %d, total: %d, current: %d\n", sum,total, ntickets);
	pthread_mutex_destroy(&mutex);




}

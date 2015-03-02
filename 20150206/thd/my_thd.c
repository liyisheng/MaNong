/*************************************************************************
  > File Name: my_thd.c
  > Author: Comst
  > Mail:750145240@qq.com 
  > Created Time: Thu 05 Feb 2015 03:27:00 PM CST
 ************************************************************************/

#include<stdio.h>
#include<pthread.h>
#include<signal.h>
int  i = 0 ;
void* thd_handle(void* arg)
{
	pthread_mutex_t* plock = (pthread_mutex_t*)arg ;

	int cnt = 100000000 ;
	while(cnt > 0)
	{
		pthread_mutex_lock(plock);
		i ++ ;
		pthread_mutex_unlock(plock);

		cnt -- ;
	}
	pthread_exit((void*)0);
}
int main(int argc, char* argv[])
{

	pthread_t thd1 ;
	pthread_t thd2 ;
	int cnt = 100000000   ;

	pthread_mutex_t lock ;
	pthread_mutex_init(&lock, NULL);

	pthread_create(&thd1, NULL, thd_handle, (void*)&lock);
	pthread_create(&thd2, NULL, thd_handle, (void*)&lock);


	pthread_join(thd1,NULL );
	pthread_join(thd2,NULL );
	printf("i : %d\n", i);

	pthread_mutex_destroy(&lock);


	return 0 ;
}

/*************************************************************************
	> File Name: thd2.c
	> Author: Comst
	> Mail:750145240@qq.com 
	> Created Time: Fri 06 Feb 2015 04:14:42 PM CST
 ************************************************************************/

#include<stdio.h>
#include<pthread.h>
#include<string.h>
#include<stdlib.h>
int* func1(int val)
{
	 int* s_val = (int*)calloc(1, sizeof(int)) ; 
	*s_val = val ;
	sleep(3) ;

	return s_val ;
}
int* func2(int val)
{
	 static int s_val  ; 
	s_val = val ;
	sleep(3) ;

	return &s_val ;
}
void* thd2_func(void* arg)
{
	func2(0);
}
int main(int argc, char* argv[])
{
	int val = 1024 ;
	int cnt = 10 ;
	int* p   ;
	pthread_t thd ;
	pthread_create(&thd, NULL, thd2_func, NULL);
	while(cnt)
	{
		p = func2(val);
		printf("val : %d\n", *p);
		cnt -- ;
	}
	pthread_join(thd, NULL);
	return 0 ;
}

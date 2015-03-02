/*************************************************************************
    > File Name: pthread_join.c
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Fri 06 Feb 2015 10:31:15 AM CST
 ************************************************************************/

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void *ThreadFunc(void *pArg)
{
	int *p = (int *)malloc(sizeof(int));
	*p = *(int *)pArg;
	printf("pArg :%d\n", *p);
	//sleep(*p);
	if(*p < 3)	
	{
		*p *= 2;
		return (void *)p;
	}
	else
	{
		*p *= 3;
		pthread_exit((void *)p);
	}
}
int main()
{
	pthread_t thdId;
	int iRet = 0;
	int *pRet = NULL;
	int num = 5;
	pthread_create( &thdId, NULL, ThreadFunc, &num);
	pthread_join(thdId, (void **)&pRet);
	printf("The first child thread ret is %d\n", *pRet); //猜测pthred_join内部实现 ,,改变了pRet的指向

	return 0;
}

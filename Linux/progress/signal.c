/*************************************************************************
    > File Name: signal.c
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Thu 16 Apr 2015 04:30:49 AM PDT
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
void ouch(int sig)
{
	printf("OUCH! - I got signal %d\n", sig);
	sleep(3);
	printf("Oh - Leave ouch! %d\n", sig);
	signal(SIGINT, SIG_DFL);
}

int main()
{
	signal(SIGINT, ouch);
	signal(SIGQUIT, ouch);
	while(1)
	{
		printf("Hello World!\n");
		sleep(1);
	}
	return 0;
}

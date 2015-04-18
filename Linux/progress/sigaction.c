/*************************************************************************
    > File Name: sigaction.c
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Thu 16 Apr 2015 05:01:16 AM PDT
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

void ouch(int sig)
{
	printf("OUCH! - I got signal %d\n", sig);
	sleep(1);
}

int main()
{
	struct sigaction act;
	act.sa_handler = ouch;
	sigemptyset(&act.sa_mask);

//	act.sa_flags = SA_RESETHAND;

	sigaction(SIGINT, &act, 0);

	while(1)
	{
		printf("Hello, world!\n");
		sleep(1);
	}

	return 0;
}



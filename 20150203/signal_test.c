/*************************************************************************
    > File Name: signal_test.c
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Tue 03 Feb 2015 04:19:24 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

void ouch(int sig)
{
	printf("OUCH! I got signal %d\n", sig);
}
	
int main()
{
//	signal(SIGINT, ouch);

	//用sigaction
	struct sigaction act;

	act.sa_handler = ouch;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;

	sigaction(SIGINT, &act, NULL);
	while(1)
	{
		printf("Hello World !\n");
		sleep(1);
	}
}





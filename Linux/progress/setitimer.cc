/*************************************************************************
    > File Name: setitimer.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Fri 17 Apr 2015 03:55:24 AM PDT
 ************************************************************************/

#include<iostream>
#include<signal.h>
#include<time.h>
#include<sys/time.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;


void sigHandler(int iSigNum)
{
	time_t tt;
	time(&tt);
	struct tm *pTm = gmtime(&tt);
	printf("%04d-%02d-%02d  %02d:%02d:%02d\n",(1900 + pTm->tm_year),(1 + pTm->tm_mon), (8+pTm->tm_hour), pTm->tm_hour,pTm->tm_min, pTm->tm_sec);
}
void InitTime(int tv_sec, int tv_usec)
{
	signal(SIGALRM, sigHandler);

	struct itimerval tm;
	tm.it_value.tv_sec = tv_sec;
	tm.it_value.tv_usec = tv_usec;
	tm.it_interval.tv_sec = tv_sec;
	tm.it_interval.tv_usec = tv_usec;

	if(setitimer(ITIMER_REAL, &tm, NULL) == -1)
	{
		perror("setitimer error");
		exit(-1);
	}


}
int main(int argc, char *argv[])
{
	InitTime(1, 0);
	while(1)
		;
	return 0;
}

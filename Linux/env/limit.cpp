/*************************************************************************
    > File Name: limit.cpp
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: 2015年04月27日 星期一 15时07分04秒
 ************************************************************************/

#include<iostream>
#include<math.h>
#include<cstdlib>
#include<cstdio>
#include<sys/types.h>
#include<sys/resource.h>
#include<sys/time.h>
#include<unistd.h>
using namespace std;



void work()
{
	FILE *f = fopen("1.txt", "w+");
	for(int i = 0; i < 10000; i++)
	{
		fprintf(f, "Do some output!\n");
		if(ferror(f))
		{
			fprintf(stderr, "Error writing to temporary file \n");
			exit(1);
		}
	}
	double x = 4.5;
	for(int i = 0; i < 12000; i++)
		x = log(x * x + 3.21);
}
int main(int argc, char *argv[])
{

	struct rusage r_usage;
	struct rlimit r_limit;
	int priority;

	work();
	getrusage(RUSAGE_SELF, &r_usage);

	printf("CPU usage : User = %ld.%06ld, System = %ld.%06ld\n",
			r_usage.ru_utime.tv_sec, r_usage.ru_utime.tv_usec,
			r_usage.ru_stime.tv_sec, r_usage.ru_stime.tv_usec);

	priority = getpriority(PRIO_PROCESS, getpid());

	printf("Current priority = %d\n", priority);

	getrlimit(RLIMIT_FSIZE, &r_limit);
	printf("Current FSIZE limit : soft = %ld, hard = %ld\n",
			r_limit.rlim_cur, r_limit.rlim_max);


	r_limit.rlim_cur = 2048;
	r_limit.rlim_max = 4096;

	printf("Setting a 2K file size limit\n");
	setrlimit(RLIMIT_FSIZE, &r_limit);

	work();
	exit(0);
	return 0;
}

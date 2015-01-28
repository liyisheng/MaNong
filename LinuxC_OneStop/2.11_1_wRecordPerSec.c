/*************************************************************************
    > File Name: 2.11_1_wRecordPerSec.c
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Sun 25 Jan 2015 11:22:07 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
int main()
{
	FILE *fp = fopen("test.txt", "a+");
	struct tm *t1;
	time_t t;
	char buf[100];
	while(1)
	{
		time(&t);
		t1 = localtime(&t);
		sprintf(buf, "%d-%d-%d %d:%d:%d\n", t1->tm_year + 1900, t1->tm_mon + 1, t1->tm_mday, t1->tm_hour, t1->tm_min, t1->tm_sec);
//		fwrite(buf, sizeof(char), strlen(buf), fp);
		fputs(buf,fp);
		fflush(fp);
		sleep(1);
	}
}

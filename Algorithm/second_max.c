/*************************************************************************
    > File Name: binary_search.c
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Sat 24 Jan 2015 06:47:33 PM PST
    > 找第二大值
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<limits.h>
int second_max(int a[], int len);
int main()
{
    
    int i;
    int a[10] = {0};
    srand(time(NULL));
    for(i = 0; i < 10; i++)
	a[i] = rand()%100;

    for(i = 0; i < 10; i++)
	printf("%d  ", a[i]);
    printf("\n%d\n", second_max(a, 10));
    return 0;
}

int second_max(int a[], int len)
{
    int i;
    int max, sec;
    max = INT_MIN, sec = INT_MIN; 
    for(i = 0; i < len; i++)
	if(a[i] > max)
	{
	    sec = max;
	    max = a[i];
	}
	else if(a[i] > sec)
	    sec = a[i];
	else 
	    continue; 
    return sec;
}

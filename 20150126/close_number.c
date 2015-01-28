/*************************************************************************
    > File Name: close_number.c
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Mon 26 Jan 2015 09:55:05 AM CST
 ************************************************************************/

#include<stdio.h>
int main()
{
	int n, i, j;
	scanf("%d", &n);
	for(i = 220; i < n; i++)	
	{
		for(j = i + 1; j < n; j++)
			if(close_number(i, j))
			{
				printf("%d %d \n", i, j);
				i = j;
				break;
			}
	}
	return 0;
}



int close_number(int a, int b)
{
	int i, sum_a = 0;	
	int j, sum_b = 0;
	for(i = 1; i < a; i++)
		if(a%i == 0)
			sum_a += i;
	for(j = 1; j < b; j++)
		if(b%j == 0)
			sum_b += j;
	if(sum_a == b && a == sum_b)
		return 1;
	else
		return 0;
}


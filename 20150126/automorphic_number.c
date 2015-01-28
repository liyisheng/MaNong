/*************************************************************************
    > File Name: automorphic_number.c
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Mon 26 Jan 2015 10:24:15 AM CST
 ************************************************************************/

#include<stdio.h>
#include<math.h>
int main()
{
	int i, n;
	scanf("%d", &n);
	for(i = 1; i < n; i++)
		if(isAutomorphic(i))
			printf("%d  ", i);
	printf("\n");

}


int isAutomorphic(int num)
{
	int i, w = 0; //位数
	int temp = num;
	int s = num*num;
	int base = 1;
	while(temp)
	{
		w++;
		temp /= 10;
	}	
	temp = 0;
	for(i = 0; i < w; i ++)
	{
		temp = temp + s%10 * base;
		base *= 10;
		s /= 10;
	}
	if(temp == num)	
		return 1;
	else
		return 0;
}


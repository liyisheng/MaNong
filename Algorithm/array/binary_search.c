/*************************************************************************
    > File Name: binary_search.c
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Sat 24 Jan 2015 06:47:33 PM PST
 ************************************************************************/

#include<stdio.h>
int binary_search(int a[], int len, int n);
int main()
{
	int a[10] = {1, 3, 4, 6, 7, 8, 9, 10};
	printf("%d\n", binary_search(a, 8, 8));
	return 0;
}

int binary_search(int *a, int len, int n)
{
	if(a == NULL || len < 0)
		return -1;
	int low, high, mid;
	low = 0, high = len - 1; 
	while(low <= high)	
	{
		//mid = (low + high)/2;
		mid = (high - low)/2 + low; //防止溢出
		if(n == a[mid])
			return mid;
		else if(n > a[mid])
			low = mid + 1; 
		else
			high = mid - 1;
	}
	return -1;
}

/*************************************************************************
    > File Name: circular_array.c
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Sun 25 Jan 2015 06:52:20 PM CST
	> 循环有序数组查找元素
 ************************************************************************/

#include<stdio.h>

int circular_array(int *a, int len, int k);
int main()
{
//	int a[10] = { 5, 6, 7, 8, 9, 10, 1, 2, 3, 4};
	int a[7] = { 2, 3, 4, 5, 6, 7, 1};
	printf("%d\n", circular_array(a, 7, 7));
	return 0;
}

int circular_array(int *a, int len, int k)
{
	int low = 0, high = len - 1, mid;
	int m2;
	int increase;
	if(a == NULL || len < 0)
		return -1;	
	while(low <= high)
	{
		mid = (low + high)/2;
		if(a[mid] == k)
			return mid;
		if( k > a[mid])
		{
			m2 = (mid + high)/2;					
			increase = (a[mid] <= a[m2] && a[m2] <= a[high]);//同样是二分查找思想，如果k大于中点值
			if((increase && k <= a[high])  || !increase)     //k值存在于右边序列的条件是 右边序列递增并且k值小
				low = mid + 1;                               //于最右边  或者是右边序列非递增
			else											//(那左边一定递增，即K值不在左边)
				high = mid - 1;
		}else
		{
			m2 = (low + mid)/2;
			increase = (a[low] <= a[m2] && a[m2] <= a[mid]);
			if((increase && k >= a[low]) || !increase)
				high = mid - 1;
			else
				low = mid + 1;
		}
	}
	return -1;	
}



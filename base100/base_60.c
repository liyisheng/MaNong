#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
60: 第60 题请编写函数fun，该函数的功能是：删去一维数组中所有相同的数，使之只剩
一个。数组中的数已按由小到大的顺序排列，函数返回删除后数组中数据的个数。
 */

int fun(int *a,int n)
{
    int i,j;
    int count = 0;
    for( i = 1; i < n; i++)
	if(a[i] == a[i-1])
	{
	    count++;
	    for(j = i ; j < n; j++)
		a[j] = a[j+1];
	    
	}
    return n - count; 

}



int main()
{
    int a[10] = {1,2,2,3,3,3,4,5,6,7};
    printf("%d\n",fun(a,10)); 
    return 0;
}

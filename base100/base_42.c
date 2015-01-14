#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define M 2
#define N 4
/*

第42 题下列程序定义了n×n 的二维数组，并在主函数中自动赋值。请编写函数fun(int
a[][n],int n),该函数的功能是：将数组右上半三角元素中的值乘以m。
*/

void fun(int a[][N],int n)
{
    int i,j;
    for(i = 0;i < n; i++)
    {		
	for(j = i; j < n; j++) 		 	
	{
	    a[i][j] *= M; 
	}
    
    }
}


int main()
{
    int i,j;
    int a[4][4] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    fun(a,4); 
    for(i = 0;i < N; i++)
    {		
	for(j = 0; j < N; j++) 		 	
	{
	    printf("%2d ",a[i][j]); 
	}
	printf("\n");
    }
    return 0;
}

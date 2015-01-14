#include<stdio.h>
#include<stdlib.h>

#define M 2
#define N 5
/*
第30题 请编写一个函数fun，它的功能是：求除一个2×m整型二维数组中最大元素的值，并将此值返回调用函数 
*/

int fun(int a[M][N]) 
{
    int i,j;   
    int max = a[0][0];
    for(i = 0; i < M; i++)
	for(j = 0; j < N; j++)	
	{
	    if(a[i][j] > max)
		max = a[i][j];
	}
    return max;
}



int main()
{
    int a[M][N] = {1, 2, 3,4,5,9,10,11,6,7};
    printf("%d\n",fun(a));
    return 0;
}

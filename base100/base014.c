#include<stdio.h>

#define M 4
#define N 5
/*
14: 第14题 请编写函数fun,函数的功能使求出二维数组周边元素之和，
作为函数值返回。二维数组中的值在主函数中赋予。
*/

int fun(int a[M][N])
{
    int i,j; 
    int aver = 0;
    for(i = 0; i < N; i++)  
    {
	aver += a[0][i];
	aver += a[M-1][i];
    } 
    for(i = 0; i < M; i++)
    {
	aver += a[i][0];
	aver += a[i][N-1];
    }
    aver -= a[0][0]; 
    aver -= a[M-1][0]; 
    aver -= a[0][N-1]; 
    aver -= a[M-1][N-1]; 
   
    return aver; 
}

int main()
{
    int a[M][N] = {1,1,1,1,1,1,2,2,2,1,1,3,3,3,1,1,1,1,1,1};
    int i,j;
    for(i = 0; i < M; i++)
    {
        for(j = 0; j < N;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }    

    printf("%d\n",fun(a));
    return 0;
}

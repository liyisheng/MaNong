#include<stdio.h>
#define M 3 
#define N 5
/*
13: 第13题 请编写一个函数void fun(int tt[m][n],int pp[n]),tt指向一个m行n列的二维函数组，
求出二维函数组每列中最小元素，并依次放入pp所指定一维数组中。二维数组中的数已在主函数中赋予。 
*/

void fun(int tt[M][N], int pp[N]);
int main()
{
    int a[M][N] = {1,2,3,4,5,2,4,6,8,10,3,5,7,9,11};
    int p[N]={0}; 
    int i,j;
    fun(a,p);
    for(i = 0; i < M; i++)
    {
    	for(j = 0; j < N;j++)
	    printf("%d ",a[i][j]);
	printf("\n");
    }

    for(i = 0; i < N; i++) 
	printf("%d ", p[i]); 
    
    printf("\n");
    return 0;
}


void fun(int tt[M][N], int pp[N])
{
    int i,j;
    int k = 0;
    int min;
    for(i = 0; i < N; i++) 
    {
	min = tt[0][i];
	for(j = 0; j < M; j++)
	{
	    if(tt[j][i] < min) 
		min = tt[j][i];
	}
	pp[k] = min;	
	k++;
    }
}

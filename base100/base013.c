#include<stdio.h>
#define M 3 
#define N 5
/*
13: ��13�� ���дһ������void fun(int tt[m][n],int pp[n]),ttָ��һ��m��n�еĶ�ά�����飬
�����ά������ÿ������СԪ�أ������η���pp��ָ��һά�����С���ά�����е��������������и��衣 
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

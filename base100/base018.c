#include<stdio.h>
#include<stdlib.h>
#define N 4
/*
 ��18�� ��д����ʵ�־���(3��3��)��ת��(�����л���)
*/
int main()
{
    int a[N][N] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    int i,j; 
    int temp;

    for(i = 0; i < N; i++)
    {
	for(j = 0; j < N; j++)
	    printf("%d ",a[i][j]);
	printf("\n");
    }	

    for(i = 0; i < N; i++)
    {
	for(j = i; j < N; j++)
	{
	    temp = a[i][j];
	    a[i][j] = a[j][i];
	    a[j][i] = temp;
	}	
    } 

    for(i = 0; i < N; i++)
    {
	for(j = 0; j < N; j++)
	    printf("%d ",a[i][j]);
	printf("\n");
    }	
    return 0;
}

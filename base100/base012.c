#include<stdio.h>
/*
12: ��12�� ���г�������n��n�Ķ�ά���飬�����������и�ֵ.
���д����fun,�����Ĺ���ʹ��������ܱ�Ԫ�ص�ƽ��ֵ����Ϊ����ֵ���ظ��������е�s�� 
*/
int main()
{
    int a[4][4];            
    int i,j;
    for(i = 0; i < 4; i++)
	for(j = 0; j < 4 ; j++)
	    a[i][j] = i*j;        

    printf("%d\n", fun(a, 4));
    for(i = 0; i < 4; i++)
    {
	for(j = 0; j < 4 ; j++)
	    printf("%d ", a[i][j]);
	printf("\n");
    }
    return 0;
}


int fun(int a[][4], int n)
{
    int aver = 0;  
    int i;
    for(i = 0; i < n; i++)
	aver += a[0][i];
    for(i = 0; i < n; i++)
	aver += a[n-1][i];
    for(i = 1; i < n-1; i++)
    {
	aver += a[i][0];
	aver += a[i][n-1];
    }
    
    aver /= 12;
    return aver;
}


#include<stdio.h>
#include<stdlib.h>
#include<string.h>


/*
28: ��28�� ���дһ������fun�����Ĺ����ǣ��ҳ�һά��������Ԫ��������ֵ�������ڵ��±꣬
����ֵ�������ڵ��±�ͨ���βδ��ء�����Ԫ���е�ֵ�����������и��衣
��������x����������n ��x�е����ݸ�����max������ֵ��index������ֵ����Ԫ�ص��±ꡣ 
*/



int fun(int x[],int n,int *max, int *index)
{
    int i;    
    *max = x[0];
    for(i = 0; i < n; i++)
    {
	if(x[i] > *max)	
	{
	    *max = x[i];
	    *index = i;
	}
    }
    return 0;
}

int main()
{
    int x[] = {192,2301,123120,123,23,3,5,12,5,123,999};
    int max,index;  
    fun(x, 11,&max,&index);
    printf("%d, %d\n", index, max);
    return 0;
}

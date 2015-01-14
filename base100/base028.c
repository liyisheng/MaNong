#include<stdio.h>
#include<stdlib.h>
#include<string.h>


/*
28: 第28题 请编写一个函数fun，它的功能是：找出一维整型数组元素中最大的值和它所在的下标，
最大的值和它所在的下标通过形参传回。数组元素中的值已在主函数中赋予。
主函数中x是数组名，n 是x中的数据个数，max存放最大值，index存放最大值所在元素的下标。 
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

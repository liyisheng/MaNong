#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
第39 题请编写函数fun，该函数的功能是：移动一维数组中的内容，若数组中由n 个
整数，要求把下标从0 到p(p 小于等于n－1)的数组元素平移到数组的最后。
*/

void fun(int a[], int n, int p)
{
    int i;
    int j = n;
    int temp[p+1];  
    for(i = 0; i <= p; i++)
    {
	temp[i] = a[i];
	j--;
    } 
    for(i = 0; i<= p; i++)
    {
	a[j] = b[i];
	j++;
    }
    
        
}



int main()
{
    
    return 0;
}

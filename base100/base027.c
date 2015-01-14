#include<stdio.h>
#include<stdlib.h>

/*
27: 第27题 请编写一个函数fun,它的功能是
求出1到m之内(含m)能背7或11整除的所有整数放在数组a中，通过n返回这些数的个数。 
*/

int fun(int a[],int m)
{
    int i;
    int index =0;
    for(i = 1; i <= m; i++)
    {
	if(!(i%7 && i%11))
	{
	    a[index] =i;
	    index++;
	}
    }
    return index;
}

int main()
{
    int a[100] = {0};
    int i = 0;
    printf("%d\n",fun(a,100)); 
   
    while(a[i]) 
    {
	printf("%d ",a[i]);
	i++;
    }
    
    return 0;
}

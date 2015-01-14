#include<stdio.h>
#include<stdlib.h>

#define M 100
/*
20: 第20题 编写函数int fun(int lim,int aa[max]),该函数的功能是求出小于
或等于lim的所有素数并放在aa数组中，该函数返回所求的素数的个数。 
*/
int prime(int);
int fun(int lim, int aa[M])
{
    int i;    
    int k = 0;
    for(i = 1; i <= lim; i++)
    {
	if(prime(i))
	{
	    aa[k++] = i;		
	}
    }
    return k;
}

int prime(int a)
{
    int i;
    if(a == 2)
	return 1;
    if(a%2 == 0 || a < 2)
	return 0;
    for(i = 3; i < a/2; i+=2)
    {
	if(a%i == 0)
	    return 0;
    } 
    return 1;
}
int main()
{
    int i = 0;
    int a[M] = {0};
    fun(100,a); 
    while(a[i]!=0 && i < 100)
    {
	printf("%d ", a[i]); 
	i++;
    }
    printf("\n");
    return 0;
}

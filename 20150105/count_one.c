#include<stdio.h>
#include<stdlib.h>
/*
    统计整数二进制中1的个数
*/
int fun(int);

int main()
{
    int a;
    while(scanf("%d",&a) == 1)
    {	
	printf("%d\n",fun(a)); 
    }
    return 0;
   
}


int fun(int a)
{
    int total = 0;
    if(a >= 0)
    {
	while(a != 0)
	{
	    if(a & 0x0001)
		total++;
	    a >>= 1;
	}
    }
    else
    {
	a = ~a;
	while(a != 0)
	{
	    if(a & 0x0001)
		total++;
	    a >>= 1;
	}
	total = 32 - total;
    }
    return total;
}

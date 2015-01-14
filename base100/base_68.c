#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
第68 题请编写函数fun，其功能时：计算并输出下列多项式的值：
sn=1+1/1!+1/2!+1/3!+1/4!+…+1/n!
*/

double fun(int n)
{
    int i;
    double an = 1.0; 
    double sum = 1.0;
    for(i = 1; i <= n; i++)
    {
	sum += an/i;
	an = an/i;
    }

    
}


int main()
{


    return 0;
}

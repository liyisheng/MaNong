#include<stdio.h>
#include<stdlib.h>

#define N 10
int main()
{
    int a[N] = {0};
    int num = 0;
    double aver = 0.0;
    while(num < N && scanf("%d",&a[num++]) == 1)
    {
	aver += a[num-1];
    }
    aver /= N;
    printf("%f\n",aver);
}

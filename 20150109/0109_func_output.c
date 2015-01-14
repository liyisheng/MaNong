#include<stdio.h>
#include<stdlib.h>

int func(int *sum, double *ave, int *max);
int main()
{
    int sum,max;    
    double ave;
    func(&sum,&ave,&max);

    printf("%d\t%f\t%d\t",sum,ave,max);
    return 0;
}


int func(int *sum, double *ave, int *max)
{
    int a;
    int count = 0;
// scanf("%d",&a);
//  *max = a;
//  *sum = a;

    *max = 0x80000000; //最小整数
    *sum = 0;
    while(scanf("%d",&a) == 1)
    {
	*sum += a;
	if(a > *max)
	    *max = a;
	count++;
    }
    *ave = (double)*sum/count;

    return 0;
}

/*************************************************************************
	> File Name: max_min.c
	> Author: liyisheng
	> Mail: liyishengchn@gmail.com
	> Created Time: Sat 24 Jan 2015 10:35:12 PM PST
    > 找出一个数组中的最大值和最小值
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<time.h>


int max_min(int a[], int len, int *max, int *min)
{
    int i, temp_max, temp_min; 
    *max = INT_MIN;
    *min = INT_MAX;
    if(len%2 == 0)
    {
        for(i = 0; i < len; i+=2)
        {
            if(a[i] > a[i + 1]) 
            {
                temp_max = a[i];
                temp_min = a[i + 1];
            }else
            {
                temp_max = a[i + 1];
                temp_min = a[i];
            }
            if(temp_max > *max)
            *max = temp_max;
            if(temp_min < *min)
            *min = temp_min;
        }
    }else
    {
        for(i = 0; i < len - 1; i+=2)
        {
             if(a[i] > a[i + 1]) 
            {
                temp_max = a[i];
                temp_min = a[i + 1];
            }else
            {
                temp_max = a[i + 1];
                temp_min = a[i];
            }
            if(temp_max > *max)
            *max = temp_max;
            if(temp_min < *min)
            *min = temp_min;
        }  
        if(a[len - 1] > *max)
            *max = a[len - 1];
        if(a[len - 1] < *min);
            *min = a[len - 1];
    }
    return  0;
}


int main()
{
    int i, max, min;
    int a[10] = {0};
    srand(time(NULL));
    for(i = 0; i < 10; i++)
	    a[i] = rand()%100;

    for(i = 0; i < 10; i++)
	printf("%d  ", a[i]);
    max_min(a, 10, &max, &min);
    printf("\n%d  %d\n", max, min);
    return 0;
 
}

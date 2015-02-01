/*************************************************************************
	> File Name: sortByZero.c
	> Author: liyisheng
	> Mail: liyishengchn@gmail.com
	> Created Time: Sun 25 Jan 2015 01:18:53 AM PST
 ************************************************************************/

#include<stdio.h>


int sortByZero(int *data, int len)
{
    int i = 0, j = len - 1;
    int key = *data;
    while(i < j)
    {
        for(;j > i && data[j] >= 0; j--);
        data[i] = data[j];
        for(;i < j && data[i] <= 0; i++);
        data[j] = data[i]; 
    }
    data[i] = key;
}

int main()
{
    int i;
    int a[6] = {-2, -1, 0, 3, -2, 0};
    sortByZero(a, 6);
    for(i = 0; i < 6; i++)
        printf("%d  ", a[i]);
    printf("\n");
    return 0;
}

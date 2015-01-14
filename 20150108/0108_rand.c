#include<stdio.h>
#include<stdlib.h>

#define N 100
int main()
{
    int i;
    int a[N];
    srand((unsigned)time(NULL));
    for(i = 0; i < N; i++)
    {
	a[i] = rand()%1000;
    }

    for(i = 0; i < N; i++)
	printf("%d\t",a[i]);
    return 0;

}


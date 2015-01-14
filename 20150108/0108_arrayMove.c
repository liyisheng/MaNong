#include<stdio.h>
#include<stdlib.h>
#define N 10

void left(int *a, int n);

int main()
{
    int a[N]; 
    int i;
    int n;
    scanf("%d",&n);
    srand(time(NULL));
    for(i = 0; i < N; i++)
    {
	a[i] = rand()%100;
    }
    
    for(i = 0; i < N; i++)
	printf("%d  ",a[i]);
    printf("\n");
    left(a,n);
    for(i = 0; i < N; i++)
	printf("%d  ",a[i]);
    printf("\n");
    return 0;

}


/*
数组循环左移n位
*/
void left(int *a, int n)
{
    int b[N];
    int i,j;
    for(i = 0; i < n; i++)
	b[i] = a[i];
    for(i = 0; i < N - n; i++)
    {
	a[i] = a[i+n];
    }
    for(j = 0; j < n; j++,i++)
	a[i] = b[j];

}


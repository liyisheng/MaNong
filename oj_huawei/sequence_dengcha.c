#include<stdio.h>


int fun(int n);
int main()
{
    int i;
    int n;
    int count = 0;
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
	count += fun(i);

    printf("%d\n",count);
}

int fun(int n)
{
    if(n == 1)
	return 2;
    else
	return fun(n - 1) + 3;
}

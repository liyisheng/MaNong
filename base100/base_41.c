#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define M 3
#define N 5

/*
第41 题请编写函数fun，该函数的功能是：将m 行n 列的二维数组中的字符数据，按
列的顺序依次放到一个字符串中。
*/


void fun(char *a, char b[M][N])
{
    int i,j,k = 0;
    for(i = 0; i < N; i++)
	for(j = 0; j < M; j++)
	    *(a + k++) = b[j][i];
    a[k] = '\0';
}

int main()
{
    char a[M][N] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','o','p'}; 
    char b[100];
    fun(b,a);
    printf("%s\n",b);
    
    return 0;
}

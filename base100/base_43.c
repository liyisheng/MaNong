#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define M 3
#define N 20
/*
第43 题编写一个函数，从传入的num 个字符串中找出一个最长的一个字符串，并通
过形参指针max 传回该串地址(用****作为结束输入的标志)。
*/



char *fun(char (*a)[N], int num)
{
    int i;
    char *max; 
    max = a[0];
    for(i = 0; i < num; i++)
    {
	if(strlen(max) < strlen(a[i]))
	    max = a[i];
    }
    return max;
}
char *fun1(char *a[])
{
    int i;
    char *max; 
    max = a[0];
    for(i = 0; i < M; i++)
    {
	if(strlen(max) < strlen(a[i]))
	    max = a[i];
    }
    return max;
}


int main()
{
    //char (*a)[N] = {"abcedfg", "bef", "uiboduaobqog"};
    char c[M][N] = {"abcedfg", "bef19812309129031", "uiboduaobqog"};
    char a1[N] = "abcedfg";
    char b1[N] = "bef198123091290123";
    char c1[N] = "uaoiqobija";
    char (*a)[N] = c;
    char *b[N] = {a1, b1, c1};
    printf("%s\n",fun(a,M));
    printf("%s\n",fun1(b));
    return 0;
}

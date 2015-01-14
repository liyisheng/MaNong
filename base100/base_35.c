#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100
/*
第35题 请编写一个函数，用来删除字符串中的所有空格
*/

void fun(char *, char*);
int main()
{
    char a[N] = "";
    char b[N];
    gets(a);
    //scanf("%s[^\n]",a);
    fun(a,b); 
    printf("%s\n",b);
 
    return 0;
}

void fun(char a[],char b[])
{
    int length = strlen(a); 
    int i;
    int index = 0;
    for(i = 0; i < length; i++)
    {
	if(a[i] == 32) 
	    continue;
	b[index++] = a[i]; 
    }   
}

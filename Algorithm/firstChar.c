/*************************************************************************
	> File Name: firstChar.c
	> Author: liyisheng
	> Mail: liyishengchn@gmail.com
	> Created Time: Sat 24 Jan 2015 11:48:37 PM PST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
int firstChar(char *a);
int main()
{

    char a[1024];
    while(gets(a))
        printf("%d\n", firstChar(a));

    return 0;
}

int firstChar(char *a)
{
    int i;
    int tmp[256]  = {0};
    for(i = 0; a[i] != '\0'; i++) 
        tmp[a[i]]++;
    for(i = 0; a[i] != '\0' && tmp[a[i]] != 1; i++);
   
    if(a[i] != '\0')
        return i;
    else
        return -1;
}

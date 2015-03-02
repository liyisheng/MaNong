/*************************************************************************
    > File Name: 1950_string_reverse.c
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Mon 23 Feb 2015 12:18:41 PM CST
	>"I am a boy" ==> "boy a am I"
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char a[10] = "abcde";
	reverse(a);
	printf("%s\n", a);
	return 0;
}

int
reverse(char *a)
{
	int i;
	int len = strlen(a);
	char temp;	
	for(i = 0; i < len/2; i++)
	{
		temp = a[i];
		a[i] = a[len - 1 - i]; 
		a[len - 1 - i ] = temp;
	}
}

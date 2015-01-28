/*************************************************************************
    > File Name: test.c
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Tue 27 Jan 2015 12:47:55 AM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>
int main()
{
	char b[100];
	char *a = "你爱欧冠哦啊队,";
	strcpy(b, a);
	printf("%s\n", b);
	return 0;

}

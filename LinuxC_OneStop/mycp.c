/*************************************************************************
    > File Name: mycp.c
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Sun 25 Jan 2015 08:24:39 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[])
{
	int ch;
	FILE *fp = fopen("aaaa", "r");	
	FILE *fp_w = fopen("2.txt", "w");
	while((ch = fgetc(fp)) != EOF)
		fputc(ch, fp_w);
	return 0;
}

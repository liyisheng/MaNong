/*************************************************************************
	> File Name: my_popen.c
	> Author: Comst
	> Mail:750145240@qq.com 
	> Created Time: Tue 03 Feb 2015 04:47:48 PM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void handle(char* str)
{
	int bg, end ;
	int tmp ;
	bg = 0; 
	end = strlen(str) - 1;
	while(bg < end)
	{
		tmp = str[bg] ;
		str[bg] = str[end] ;
		str[end] = tmp ;
		bg ++ ;
		end -- ;
	}
}
int main(int argc, char* argv[])
{	
	char src[1024] ;
	while(memset(src, 0, 1024), gets(src) != NULL )
	{
		handle(src);
		printf("pid: %d  %s\n", getpid() ,src );
	}
	return 0 ;
}

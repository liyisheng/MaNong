/*************************************************************************
	> File Name: my_cwd.c
	> Author: Comst
	> Mail:750145240@qq.com 
	> Created Time: Wed 28 Jan 2015 03:43:26 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
int main(int argc, char* argv[])
{
	char* pdir = getcwd(NULL, 0);
	printf("cwd1: %s\n", pdir);
	chdir("/home/comst");
	 pdir = getcwd(NULL, 0);
	printf("cwd2: %s\n", pdir);
	while(1);
	return 0 ;
}


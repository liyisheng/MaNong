/*************************************************************************
	> File Name: test.c
	> Author: Comst
	> Mail:750145240@qq.com 
	> Created Time: Tue 27 Jan 2015 09:37:48 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10000000
int main(int argc, char* argv[])
{
	FILE** fp_arr = (FILE**)calloc(MAX, sizeof(FILE*));	
	char buf[1024] = "" ;
	int index ;
	for(index = 0; index < MAX; index ++)
	{
		memset(buf, 0, 1024);
		sprintf(buf, "%d.txt", index);
		fp_arr[index] = fopen(buf, "w");
		if(fp_arr[index] == NULL)
		{
			printf("index: %d\n",index);
			break ;
		}
	}
	return 0 ;
}

/*************************************************************************
	> File Name: my_popen.c
	> Author: Comst
	> Mail:750145240@qq.com 
	> Created Time: Tue 03 Feb 2015 04:47:48 PM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc, char* argv[])// ./my_reverse
{	
	printf("pid: %d\n", getpid());
	FILE* fp_in ;
	char cmd[1024] ;
	char str[1024] ;
	while(memset(str, 0, 1024), fgets(str, 1024, stdin) != NULL)
	{
		memset(cmd, 0, 1024);
		sprintf(cmd, "%s %s", argv[1], str);
		fp_in = popen(cmd, "r") ;
		if(fp_in == NULL)
		{
			perror("popen");
			exit(1);
		}
		memset(str, 0, 1024) ;
		fscanf( fp_in, "%s", str );
		printf("res: %s\n", str);

	}
	return 0 ;
}

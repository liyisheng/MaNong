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
	FILE* fp_out ;
	char cmd[1024] ;
	char str[1024] ;
	fp_out = popen(argv[1], "w") ;
	if(fp_out == NULL)
	{
		perror("popen");
		exit(1);
	}
	while(memset(str, 0, 1024), fgets(str, 1024, stdin) != NULL)
	{
		fputs(str, fp_out);
		fflush(fp_out);

	}
	pclose(fp_out);
	return 0 ;
}

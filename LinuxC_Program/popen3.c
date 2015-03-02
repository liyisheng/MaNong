/*************************************************************************
    > File Name: popen3.c
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Thu 05 Feb 2015 10:39:15 AM CST
 ************************************************************************/

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main()
{
	FILE *read_fp;

	char buffer[BUFSIZ + 1];
	int chars_read;

	memset(buffer, 0, sizeof(buffer));

	read_fp = popen("ps ax", "r");
	if(read_fp != NULL)
	{
		chars_read = fread(buffer, sizeof(char), BUFSIZ, read_fp);
		while(chars_read > 0)
		{
			buffer[chars_read - 1] = '\0';
			printf("Reading %d: -\n %s", BUFSIZ, buffer);
			chars_read = fread(buffer, sizeof(char), BUFSIZ, read_fp);
		}
		pclose(read_fp);
		exit(1);
	}
	exit(1);

}

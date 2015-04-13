/*************************************************************************
    > File Name: strFind.c
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Fri 10 Apr 2015 05:36:59 AM PDT
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

const char *strFind(const char *string, const char *substring)
{
	int i, j;
	assert(string != NULL && substring != NULL);
	int m = strlen(string);
	int n = strlen(substring);
	if(m < n)
		return NULL;
	for(i = 0; i <= m-n; ++i)
	{
		for(j = 0; j < n; j++)
		{
			if(string[i + j] != substring[j])
				break;
		}
		if(j == n)
			return string + i;
	}
	return NULL;
}
int main()
{
	char *a = "ababcabcacbab";
	char *b = "abcac";
	puts(strFind(a, b));
}


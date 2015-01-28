/*************************************************************************
    > File Name: 2034_long_substring.c
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Sat 24 Jan 2015 02:49:15 AM PST
	>查找两个字符串a,b中的最长公共字串
 ************************************************************************/

#include<stdio.h>
#include<string.h>
char *substring(char *a, char *b);
int main()
{ 
//	char a[100] = "abcdefghijklmnop";
//	char b[100] = "abcsafjklmnopqrstuvw";
	char a[100];	
	char b[100];	
	scanf("%s", a);
	scanf("%s", b);

	printf("%s\n", substring(a, b));
	return 0;
}


char *substring(char *a, char *b)
{
	int i, j, k = 1, max = 1, index = 0;
	int len_a = strlen(a);
	int len_b = strlen(b);
	for(i = 0; i < len_a; i++)
	{
		for(j = 0; j < len_b; j++)	
		{
			while(memcmp(a + i, b + j, k) == 0)
			{
				k++;
				if((k + j) > len_b || (k + i) > len_a)
					break;
			}	
			if(max < k - 1)
			{
				max = k - 1;
				index = i;
			}
			k = 1;
		}
	}
	if(max == 1)
		return NULL;
	else
	{
		a[index + max] = '\0';
		return a + index;
	}
}



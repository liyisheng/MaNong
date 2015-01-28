/*************************************************************************
    > File Name: 2034_long_substring.c
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Sat 24 Jan 2015 02:49:15 AM PST
	>计算两个字符串的最大公共字串的长度
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<ctype.h>
int substring(char *a, char *b);
void upToLow(char *a);
int main()
{ 
//	char a[100] = "abcdefghijklmnop";
//	char b[100] = "abcsafjklmnopqrstuvw";
	char a[100];	
	char b[100];	
	scanf("%s %s", a, b);
	
	upToLow(a);	
	upToLow(b);	
	printf("%d\n", substring(a, b));
	return 0;
}

void upToLow(char *a)
{
	int i;
	for(i = 0; a[i] != '\0'; i++)
		if(isupper(a[i]))
			a[i] = a[i] + 32;
}

int substring(char *a, char *b)
{
	int i, j, k = 1, max = 0, index = 0;
	int len_a = strlen(a);
	int len_b = strlen(b);
	if(len_a == 0 || len_b == 0)
		return 0;
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
	return max;
}



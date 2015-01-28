/*************************************************************************
    > File Name: replaceStr.c
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Mon 26 Jan 2015 09:39:32 AM CST
	>rep(char *s, char *s1, char *s2) 将s中所有属于s1的字符用s2中对应的字符替换
 ************************************************************************/

#include<stdio.h>
#include<string.h>
int rep(char *s, char *s1, char *s2);
int main()
{
	char s[1024];
	char s1[256];
	char s2[256];
	scanf("%s", s);
	scanf("%s", s1);
	scanf("%s", s2);
	rep(s, s1, s2);
	printf("%s", s);
	return 0;
}


int rep(char *s, char *s1, char *s2)
{
	int i, j;
	int len_s1 = strlen(s1);	
	for(i = 0; i < len_s1; i++)
	{
		for(j = 0; s[j] != '\0'; j++)
			if(s[j] == s1[i])
				s[j] = s2[i];
	}
	return 0;

}

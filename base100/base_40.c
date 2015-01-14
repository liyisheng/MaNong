#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 5
/*
第40 题请编写函数fun，该函数的功能是移动字符串中内容，移动的规则如下：把第
1 到第m 个字符，平移到字符串的最后，把第m＋1 到最后的字符移到字符串的前部。

*/

void fun(char *s,int m)
{
    char b[N];
    int i,j;
    memcpy(b, s, m); 
    for(i = 0; i < strlen(s) - m; i++)
	s[i] = s[i+m];
    for(j = 0; j < m; j++,i++)
	s[i] = b[j];
}

int main()
{
    char s[] = "abcdefghij"; 
    fun(s, N);
    printf("%s\n",s);
    return 0;
}

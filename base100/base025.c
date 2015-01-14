#include<stdio.h>
#include<stdlib.h>

/*
第25题 请编写一个函数fun，它的功能是：比较两个字符串的长度,
(不得调用c语言提供的求字符串长度的函数)，函数返回较长的字符串。若两个字符串长度相同，则返回第一个字符串。     
*/


char *fun(char *s, char *t)
{
    int length_s = 0,length_t = 0;  
    int i = 0;
    while(s[i] != '\0' && t[i] != '\0')
    {
	if(s[i] == '\0')
	    return t;	
	if(t[i] == '\0')
	    return s;
	length_s++;	
	length_t++;
	i++;	
    }
    return s;
}

int main()
{
    char a[] = "abcdefgh";
    char b[] = "abce";
    printf("%s\n",fun(a,b));
    return 0;
}

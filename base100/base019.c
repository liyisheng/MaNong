#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
19: 第19题 编写函数fun,该函数的功能是：从字符中删除指定的字符，同一字母的大、小写按不同字符处理。
*/

void fun(char s[], char c)
{
    int i = 0;
    int j;
    int length = strlen(s);
    while(s[i] != '\0')
    {
	if(s[i] == c)
	{
	    for(j = i; j < length-1; j++) 
	    {
		s[j] = s[j + 1];
		s[length-1] = '\0';
	    }
	} 
	i++;
    }
}


int main()
{
    char s[] = "abcedfajoguouHoiabaouOUUo";
    printf("%s\n", s);
    fun(s, 'a');
    printf("%s\n", s);
    return 0;
}


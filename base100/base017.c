#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
请编写一个函数fun(char *s)，该函数的功能使把字符串中的内容拟置
*/

void fun(char *s )
{
    int i;
    int length = strlen(s);
    int num = length - 1;
    char s1[10];
    char *s2;
    char *temp =s;
    for(i = 0; i < length; i++)
    {
	s1[i] = *temp;
	temp++;
    }
    s1[length] = '\0';
    s2 = s1;
    while(*s2 != '\0')
    {
        *( s+num) = *s2;
        num--;
        s2++;
    }
}

int main()
{
    char a[] = "aoiuobajfqogo";
    fun(a);
    printf("%s\n",a);
    return 0;
}


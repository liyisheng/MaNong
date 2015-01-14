#include<stdio.h>
#include<stdlib.h>
#include<string.h>


/*
第38 题请编写函数fun，它的功能是：求出ss 所指字符串中指定字符的个数，并返回
此值。
*/
int fun(char * ,char);

int main()
{
    char a[] = "abcd abou qaaauaa" ;
    printf("%d\n",fun(a,'a'));
    
    return 0;
}

int fun(char *s, char c)
{
    int i = 0;
    int count = 0;
    while(s[i] != '\0')
    {
	if(s[i++] == c)
	    count++;
    }

    return count;
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
23: 第23题 请编写函数fun，该函数的功能是：判断字符串是否为回文?若是则函数返回1，
主函数中输出yes，否则返回0，主函数中输出no。回文是指顺读和倒读都是一样的字符串。 
*/

int fun(char *s)
{
    int length = strlen(s);
    int i; 
    for(i = 0; i < length/2; i++) 
    {
	if(s[i] != s[length - 1 - i])	
	    return 0;
    }
    return 1;
}

int main()
{
    char a[100];
    while(1)
    {
	scanf("%s",a);
	if(fun(a))
	    printf("yes\n");
	else
	    printf("no\n");
    }
    return 0;
}


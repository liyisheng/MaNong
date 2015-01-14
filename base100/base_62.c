#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
第62 题请编写函数fun，该函数的功能是：统一一含字符串中单词的个数，作为函数
值返回。一行字符串在主函数中输入，规定所有单词由小写字母组成，单词之间由若干个空
格格开，一行的开始没有空格。
*/


int fun(char *a)
{
    int i; 
    int length = strlen(a);
    int count = 0;
    for(i = 0; i < length; i++)
    {
	if(a[i] != ' ')
	{
	    count++;
	    while(a[i] != ' ' && a[i] != '\0')
		i++;
	}
    }
    return count;
}


int main()
{

    char a[100];
    //scanf("%s",a);
    gets(a);
    printf("%d\n",fun(a));
    return 0;
}


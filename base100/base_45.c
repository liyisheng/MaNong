#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
第45 题假定输入的字符串中只包含字母和*号。请编写函数fun，它的功能是：只删除
字符串前导和尾部的*号，串中字母之间的*号都不删除。形参n 给出了字符串的长度，形
参h 给出了字符串中前导*号的个数，形参e 给出了字符串中最后的*个数。在编写时不得使
用c 语言给提供得字符串函数。
*/

void fun(char *a, int n, int h, int e)
{
    int i = 0;
    char *p; 
    for(p = a + h; p < a + n - e; p++)
    {
	*(a + i) = *p;
	i++;
    }
    *(a + i) = '\0';
}
char *fun1(char *a, int n, int h, int e)
{
    a = a + h;
    *(a + n - h - e) = '\0';
    return a;
}

int main()
{
    char a[] = "*****abcdefghijklmn*******";
    fun1(a,26,5,7); 
//    char *p = a;
    printf("%s\n",fun1(a,26,5,7));
    return 0;
}

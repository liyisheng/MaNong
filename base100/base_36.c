#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define M 100
/*
第36 题假定输入的字符串中只包含字母和*号。请编写函数fun，它的功能是：将字符
串中的前导*号全部移到字符串的尾部。
*/

char *fun(char *a)
{
    int i = 0,count = 0;
    int length = strlen(a); 
    char b[M] = "";
    strcpy(b,a);
   /* 
    while(a[count++] == '*')
	;
    count--;
*/
    while(b[i++] == '*')
    {
	count++;
    }
    for(i = 0; i < length-count; i++)
	*(a+i) = b[i+count];	
    for(i = length-count; i < length; i++)
	*(a+i) = '*';
    return a;
}



int main()
{
    char a[] = "******ojoafobuqjbao"; 
    printf("%s\n",fun(a));
    return 0;
}

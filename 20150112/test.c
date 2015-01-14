#include<stdio.h>
#include<stdlib.h>
int main()
{
    
    char a[] = "you";
    char b[] = "how";
    printf("%d\n",strcmp(a,b));
    
    char a1 = '8';
    char a2 = '1';

    char a3 = (a1 - '0' + a2 - '0')/10 + '0';
    printf("%c\n",a3);

    return 0;
}


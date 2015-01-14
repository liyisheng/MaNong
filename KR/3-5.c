#include<stdio.h>
#include<stdlib.h>


void my_itoa(int n, char s[])
{
    int i, j, k,sign;
    unsigned temp;
    i = 0;
    if(n < 0)
    { 
	temp = 1 - (n + 1);//最大负数
	sign = -1;
    }else
    {
	temp = n;
	sign = 1;
    }
    do
    {
	s[i++] = temp%10 + '0';
    }while(temp /= 10);
    if(sign < 0)
	s[i++] = '-';
    s[i] = '\0';

    for(j = 0,i--; j < i; i--, j++)
	k = s[j],s[j] = s[i],s[i] = k;
}


int main()
{
    char a[100] = "";
    my_itoa(123456, a);   
    printf("%s\n", a);
    return 0;
}

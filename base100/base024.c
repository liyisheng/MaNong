#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
24: 第24题 请编写一个函数fun，它的功能是：将一个字符串转换为一个整数(不得调用c语言提供的将字符串转换为整数的函数)。 
*/

int fun(char *s)
{           
    int length = strlen(s);
    int i,c, num = 0;
    int base = 1;
    int flag = 0;
    if(s[0] == '+')
	flag = 1; 
    else if(s[0] == '-')
	flag = -1;
    else if(s[0] >= '0' && s[0] <= '9')
	{
	    for(i = 0; i < length; i++)
	    {	
		c = s[i] - 48;
		if(c < 0 || c > 9)
		    return -1;
		num = num*10 + c;	
	    }
	    return num;	     
	}	
    else 
	return -1;

    if(flag == 1 || flag == -1)
	for(i = 1; i < length; i++)
	{	
	    c = s[i] - 48;
	    if(c < 0 || c > 9)
		return -1;
	    num = num*10 + c;	
	}
    return flag*num;
}


int main()
{
    char s[100];
    while(1)
    {
	scanf("%s",s);
	printf("%d\n",fun(s));
    }
    return 0;
}

 

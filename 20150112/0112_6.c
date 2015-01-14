#include<stdio.h>
#include<stdlib.h>
#include<string.h>


/*
将包含字符数字的字符串分开 ,使得 分开后的字符串前一部是数字，后一部分是字母。例如 “h1ell2o3” ->"123hello"
*/


int my_atoi(char *src)
{
    int i;
    int result = 0;
    for(i = 0; src[i] != '\0'; i++)
    {
	if(src[i] >= '0' && src[i] <= '9')
	    result = result * 10 + (src[i] - '0');
	else
	    return -1;
    }
    return result;
}

int main()
{
    char a[8] = "1234567A";

    printf("%d\n",my_atoi(a));
    return 0;
}

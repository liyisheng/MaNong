#include<stdio.h>
#include<stdlib.h>
#include<string.h>


/*
   将字符串中的空格替换成“%020”  
*/


char *replace_space(const char *src, char *out)
{
    int i;
    int j = 0;
    for(i = 0; src[i] != '\0'; i++)
    {
	if(src[i] == ' ')	
	    out[j++] = '%',out[j++] = '0',out[j++] = '2',out[j++] = '0';
	else
	    out[j++] = src[i];
    }
    out[j] = '\0';

    return out;
}

int main()
{
    char a[30] = "hello   world   how    ";
    char b[100];
    printf("%s\n",replace_space(a, b));
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


/*
删除字符串中指定的字符。 例如 “abcdaefaghiagkl” 删除a 后“bcdefghigkl”
*/


char *depart(char *src, char c)
{
    int i;
    int k = 0;
    for(i = 0; src[i] != '\0'; i++)
	if(src[i] != c)
	    src[k++] = src[i];
    src[k] = '\0';
    return src;
}

int main()
{
    char a[20] = "abcdaefaghiagkl";

    printf("%s\n",depart(a,'a'));
    return 0;
}

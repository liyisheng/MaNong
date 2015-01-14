#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100

char *shrink_space(char *dest, const char *src, size_t n);
int main()
{
    char a[N];
    char b[N];
    char c;
    int i = 0;
    while( i < N && scanf("%c",&c) == 1)
    {
	if(c == '#')
	    break;
	a[i++] = c;
    }
    a[i]='\0';
	
    printf("%s\n",shrink_space(b,a,i));

    return 0;
}


char *shrink_space(char *dest, const char *src, size_t n)
{
    int i;
    int j = 0;
    int flag = 0;
    for( i = 0; i < n; i++)
    {
	if(src[i] == '\t' || src[i] == '\n' || src[i] == '\t' || src[i] == ' ')
	{
	    if(flag == 0)
	    {
		dest[j++] = ' ';
		flag = 1;
	    }
	}
	else
	{
	    flag = 0;
	    dest[j++] = src[i];
	}
    }
    dest[j] = '\0';
    return dest;
} 

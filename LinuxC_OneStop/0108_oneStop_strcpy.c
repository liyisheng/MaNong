#include<stdio.h>






char *strcpy(char *dest, const char *src)
{
    int i;
    for(i = 0; src[i]!= '\0'; i++)
	*(dest + i) = *(src + i);
    *(dest+i) = '\0';
    return dest;
}

int main()
{
    char a[10];
    char *b = "abcdefg";
    printf("%s\n",strcpy(a,b));
}

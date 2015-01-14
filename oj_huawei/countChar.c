#include<stdio.h>

int countChar(char *str, char c)
{
    int i;
    int count = 0;
    for(i = 0; str[i] != '\0'; i++)
    {
	if(str[i] == c)
	    count++;
    }
    return count;
}
int main()
{
    char a[100];
    char c;
    gets(a);
    scanf("%c",&c);
    printf("%d\n",countChar(a, c));
    return 0;
}

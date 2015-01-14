#include<stdio.h>
#include<ctype.h>
#include<string.h>

int isUniq(char *str, char c);
int CountUniqChar(char *str)
{
    int char_num[128] = {0};
    int i;
    int length = strlen(str);
    int count = 0;
    for(i = 0; str[i] != '\0'; i++)
    {
	if(isascii(str[i]))
	    char_num[str[i]]++;
    }
    for(i = 0; i < 128; i++)
    {
	if(char_num[i])
	    count++;
    }
    return count;
}

int main()
{
    char s[15000];
    gets(s);
    printf("%d\n",CountUniqChar(s));
    return 0;
}

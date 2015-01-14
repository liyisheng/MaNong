#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int len(char *s);
int main()
{
    char s[200];
    gets(s);
    printf("%d\n",len(s));
}

int len(char *s)
{
    int i;
    int j = 0;
    int length = strlen(s);
    for(i = length - 1; i >= 0 && (s[i] == ' ' ||s[i] == '\t'); i--)
	; 
    if(i == -1 )
	return 0;
    while(i >=0 && s[i] != ' ' && s[i] != '\t')
    {
	i--;
	j++;
    }
    return j;
}


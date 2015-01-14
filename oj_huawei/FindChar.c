#include<stdio.h>
void FindChar(char *pInputString, char *pChar)
{
    int i,j;
    char temp;
    for(i = 0; pInputString[i] != '\0'; i++)
    {
	temp = pInputString[i];
	for(j = 0; pInputString[j] != '\0'; j++)	
	    if(pInputString[j] == pInputString[i] && j != i)
		break;
	if(pInputString[j] == '\0')
	{
	    *pChar = pInputString[i];
	    return;
	}
    }
    *pChar = '.';
}
int main()
{
    char c;
    char a[15000];
    gets(a);
    FindChar(a,&c);
    printf("%c\n",c);
    return 0;
}

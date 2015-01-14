#include<stdio.h>
#include<ctype.h>

char *MarkNum(char *str, char *b)
{
    int i;  
    int k = 0; 
    int state = 1;
    for(i = 0; str[i] != '\0'; i++)
    {	
	if(isalpha(str[i]))
	{
	    if(state == 0)
	    {
		state = 1;
		b[k++] = '*';
	    }
	    b[k++] = str[i];
	}
	else if(isdigit(str[i]))
	{
	    if(state == 1)
	    {
		state = 0;
		b[k++] = '*';
	    }
	    b[k++] = str[i];
	}
    }
    if(isdigit(str[i - 1]))
	b[k++] = '*';
    b[k] = '\0';

    return b;
}


int main()
{
    char str[14000];
    char b[15000];
    gets(str);
    printf("%s\n", MarkNum(str, b));
    return 0;
}


/*************************************************************************
    > File Name: pwd_crack.c
    > Author: lys
    > Mail: liyishengchn@gmail.com 
    > Created Time: Fri 23 Jan 2015 06:52:07 PM PST
 ************************************************************************/
#include<stdio.h>
#include<ctype.h>
char *pwd_crack(char *entry);
int main()
{
	char a[1024];
	scanf("%s", a);
	printf("%s", pwd_crack(a));
	return 0;
}

char *pwd_crack(char *entry)
{
	int i = 0;
	while(entry[i] != '\0')
	{
		if(isupper(entry[i]))
		{
			entry[i] = entry[i] + 32;
			if(entry[i] == 'z')
				entry[i] = 'a';
			else
				entry[i] = entry[i] + 1;
		}else if(islower(entry[i]))
		{
			if(entry[i] <= 'c')
				entry[i] = '2';
			else if(entry[i] <= 'f')
				entry[i] = '3';
			else if(entry[i] <= 'i')
				entry[i] = '4';
			else if(entry[i] <= 'l')
				entry[i] = '5';
			else if(entry[i] <= 'o')
				entry[i] = '6';
			else if(entry[i] <= 's')
				entry[i] = '7';
			else if(entry[i] <= 'v')
				entry[i] = '8';
			else if(entry[i] <= 'z')
				entry[i] = '9';
		}
		i++;
	}
	return entry;	
}

#include<stdio.h>

#define MAXLINE 1000
int my_getline(char s[], int lim);
void copy(char to[], char from[]);

int main()
{
    int len;
    int max = 0;
    char line[MAXLINE];
    char longest[MAXLINE];
     
    while((len = my_getline(line, MAXLINE)) > 0)
	if(len > max)
	{
	    max = len;
	    copy(longest, line);
	}

    printf("%s",longest);

    return 0;

}

int my_getline(char s[], int lim)
{
    int c, i;
    for(i = 0; (c = getchar()) != EOF && c != '\n' && i < lim - 1; i++)
	s[i] = c;
    if(c == '\n')     
    {
	s[i] = c;
	i++;
    }
    s[i] = '\0';
    return i;
}

void copy(char to[], char from[])
{
    int i;
    for(i = 0; from[i]!= '\0';i++)
	to[i] = from[i];
}

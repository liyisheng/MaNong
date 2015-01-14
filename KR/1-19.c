#include<stdio.h>
#include<string.h>
#define N 100
void reverse(char *s);
int my_getline(char s[], int lim);

int main()
{
    char s[N];
    while( my_getline(s, N) > 0)  
    {
	reverse(s);			
	printf("%s\n",s);
    }
    return 0;
}



void reverse(char *s)
{
    int i = 0;
    int j = strlen(s) - 1;
    int tmp;
    for(; i<= j; i++,j--)
    {
	tmp = s[i];
	s[i] = s[j];
	s[j] = tmp;
    }
}


int my_getline(char s[], int lim)
{
    int i;
    int c;
    for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
	s[i] = c;  
    if(c == '\n')
	s[i++] = c;
    s[i] = '\0';
    
    return i;
}

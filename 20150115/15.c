#include<stdio.h>

int Index(char *s, char c);


void rep(char *s, char *s1, char *s2)	
{
    int i;
    int index;
    for(i = 0; s[i] != '\0'; i++)
    {
	index = Index(s1, s[i]);
	if(index >= 0)
	    s[i] = s2[index];
    }

}


int Index(char *s, char c)
{
    int i;
    for(i = 0; s[i] != '\0'; i++)
    {
	if(s[i] == c)
	    return i;
    }
    return -1;
}


int main()
{
    char s1[1000];
    char s2[1000]; 
    char s3[1000];
    gets(s1);
    gets(s2);
    gets(s3);	
    rep(s1, s2, s3); 
    printf("%s\n", s1);
    return 0;
}

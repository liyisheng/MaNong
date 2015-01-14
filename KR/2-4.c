#include<stdio.h>
#include<stdlib.h>
/*
   将字符串s1中任何与字符串s2中字符匹配的字符都删除
*/


void my_squeeze(char s1[], char s2[])
{
    int i,j,k;
    for(i = k = 0; s1[i] != '\0'; i++)
    {
	for(j = 0; s2[j] != '\0' && s2[j] != s1[i]; j++)
	    continue;
	if(s2[j] == '\0')
	    s1[k++] = s1[i];
    }
    s1[k] = '\0';
}


int main()
{
    char s1[] = "abcdefghijklmnopqrstuvwxyz";
    char s2[] = "mnopq";
    printf("%s\n", s1);
    my_squeeze(s1, s2);
    printf("%s\n", s1);
}

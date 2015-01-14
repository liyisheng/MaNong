#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

/*
编写函数expand(s1,s2),将字符串s1中类似于a-z一类的速记符号在字符串s2中扩展为等价的完整列表abc..xyz。该函数可以处理
大小写字母和数字，并可以处理a-b-c、a-z0-9与-a-z等类似的情况。作为前导和尾随的-字符原样排印
*/

void expand(char *s1, char *s2);
int main()
{

    char *s1 = "ABCDEF-a-z";
    char s2[100];
    expand(s1,s2);
    printf("%s\n",s2);
    return 0;
}


void expand(char *s1, char *s2)
{
    int i,k = 0;
    char j;
    for(i = 0; s1[i] != '\0'; i++)
    {
	if(s1[i] == '-' && s1[i + 1] > s1[i - 1])
	{
	    if(isdigit(s1[i - 1]) && isdigit(s1[i + 1]))
	    {
		for(j = s1[i - 1] + 1; j < s1[i + 1]; j++)
		    s2[k++] = j;
	    }
	    else if(s1[i - 1] >= 'a' && s1[i - 1] <= 'z' && s1[i + 1] >='a' &&  s1[i + 1] <= 'z')
		for(j = s1[i - 1] + 1; j < s1[i + 1]; j++)
		    s2[k++] = j;
	    else if(s1[i - 1] >= 'A' && s1[i - 1] <= 'Z' && s1[i + 1] >= 'A' && s1[i + 1] <= 'Z')
		for(j = s1[i - 1] + 1; j < s1[i + 1]; j++)
		    s2[k++] = j;
	    else
		s2[k++] = s1[i];
	}else
	{
	    s2[k++] = s1[i];
	}
    }
    s2[k] = '\0';
}

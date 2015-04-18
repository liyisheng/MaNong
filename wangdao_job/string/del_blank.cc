/*************************************************************************
    > File Name: del_blank.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Mon 13 Apr 2015 08:14:04 AM PDT
 ************************************************************************/

#include<iostream>
#include<string.h>
using namespace std;

char* fun(char *s)
{
	int i = 0, j = 0;
	while(s[j] == ' ')
		j++;
	int len = strlen(s) - 1;
	while(s[len] == ' ')
		len--;
	s[len + 1 ] = '\0';
	while(s[j] != '\0')
	{
		while(s[j] == ' ')
			j++;
		if(s[j - 1]== ' ' && i != 0)
			s[i++] = ' ';
		s[i++] = s[j++];
	}
	s[i] = '\0';
	return s;
}
int main(int argc, char *argv[])
{
	char a[] = "    abc b c  ddfa  faqf  ";
	cout << fun(a);
	return 0;
}

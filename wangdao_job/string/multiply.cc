/*************************************************************************
    > File Name: multiply.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Mon 13 Apr 2015 06:47:06 AM PDT
 ************************************************************************/

#include<iostream>
#include<assert.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

void multiply(const char *a, const char *b)
{
	assert( a != NULL && b != NULL);
	int ca = strlen(a);
	int cb = strlen(b);
	int *s = new int[ca + cb](); /分配存储空间,初始化0

	for(int i = 0; i < ca; ++i)
		for(int j = 0; j < cb; ++j)
			s[i + j + 1] += (a[i] - '0') * (b[j] - '0');

	for(int i = ca + cb - 1; i >= 0; --i)
		if(s[i] >= 10)
		{
			s[i-1] += s[i]/10;
			s[i] %= 10;
		}

	char *c = new char[ca + cb];
	int i = 0;
	while(s[i] == 0) i++;
	int j = 0;
	for(j = 0; i < ca + cb; ++i, ++j)
		c[j] = s[i] + '0';
	c[j] = '\0';
	cout << c << endl;
	free(s);
	free(c);
}
int main(int argc, char *argv[])
{
	multiply("111123414124124124", "555555555125151512512");
	return 0;
}

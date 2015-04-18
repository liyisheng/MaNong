/*************************************************************************
    > File Name: isUniqueCharString.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Fri 17 Apr 2015 12:51:06 AM PDT
 ************************************************************************/

#include<iostream>
#include<assert.h>
#include<string.h>
using namespace std;

bool char_set[256];

int isUniqueCharString(const char* str)
{
	assert(str != NULL);
	for(int i = 0; i < strlen(str); ++i)
	{
		if(char_set[str[i]])
			return  0;
		char_set[str[i]] = true;
	}
	return 1;
}
//如果字符串 仅包含'a' - 'z', 可以使用bit-map实现
int isUniqueCharString2(const char* str)
{
	assert(str != NULL);
	int checker = 0;
	int len = strlen(str);
	for(int i = 0; i < len; ++i)
	{
		int val = str[i] - 'a';
		if((checker & (1 << val)) > 0)
			return 0;
		checker  |= (1 << val);
	}
}
int main(int argc, char *argv[])
{
	const char *a = "abcdaefghijklmn";
	cout << isUniqueCharString(a);
	return 0;
}

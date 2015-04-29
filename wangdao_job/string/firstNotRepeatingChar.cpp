/*************************************************************************
    > File Name: firstNotRepeatingChar.cpp
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: 2015年04月27日 星期一 19时48分21秒
 ************************************************************************/

#include<iostream>
#include<assert.h>
using namespace std;

void FirstNotRepeatingChar(const char* pString)
{
	assert(pString != NULL);
	int *hashTable = new int[256]();	

	const char *hashKey  = pString;

	while(*hashKey != '\0')
		hashTable[*hashKey++] ++;
	hashKey = pString;
	while(*hashKey != '\0')
	{
		if(hashTable[*hashKey] == 1)
		{
			cout << *hashKey << endl;
			return;
		}
		hashKey++;
	}
}

int main(int argc, char *argv[])
{
	const char *s = "abaccdeff";
	FirstNotRepeatingChar(s);
	return 0;
}

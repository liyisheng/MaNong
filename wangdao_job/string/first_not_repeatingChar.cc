/*************************************************************************
    > File Name: first_not_repeatingChar.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Thu 16 Apr 2015 08:11:50 PM PDT
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<assert.h>
using namespace std;
void FirstNotRepeatingChar(const char* pString)
{
	assert(pString != NULL);
	unsigned int hashTable[256] = {0};
	const char* pHashKey = pString;
	while(*pHashKey != '\0')
		hashTable[*(pHashKey++)] ++;

	pHashKey = pString;
	while(*pHashKey != '\0')
	{
		if(hashTable[*pHashKey] == 1)
		{
			printf("%c\n", *pHashKey);
			return;
		}
		pHashKey ++;
	}

}

int main(int argc, char *argv[])
{
	const char *a = "abaccdeff";
	FirstNotRepeatingChar(a);
	return 0;
}

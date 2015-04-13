/*************************************************************************
    > File Name: reverse_sentence.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Mon 13 Apr 2015 07:06:18 AM PDT
 ************************************************************************/

#include<iostream>
using namespace std;

void reverse(char *pb, char *pe)
{
	if(pb == NULL || pe == NULL)
		return;
	while(pb < pe)
	{
		char tmp = *pb;
		*pb = *pe;
		*pe = tmp;
		pb++, pe--;
	}
}

char *reverse_sentence(char *pData)
{
	char *pBegin = pData;
	char *pEnd = pData;
	while(*pEnd != '\0')
		pEnd++;
	reverse(pBegin, --pEnd);

	while(*pBegin != '\0')
	{
		if(*pBegin == ' ')
		{
			pBegin++;
			pEnd++;
			continue;
		}else if(*pEnd == ' ' || *pEnd == '\0')
		{
			reverse(pBegin, --pEnd);
			pBegin = ++pEnd;
		}else
			pEnd++;
	}
	return pData;
}

int main(int argc, char *argv[])
{
	string a = "Today is Friday!";
	cout << reverse_sentence(a.c_str());
	return 0;
}

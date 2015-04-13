/*************************************************************************
    > File Name: kmp_search.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Fri 10 Apr 2015 06:12:19 AM PDT
 ************************************************************************/

#include<iostream>
using namespace std;

int kmp_search(const char *src, int slen, const char *patn, int plen, const
		int *nextval, int pos)
{
	int i = pos, j = 0;	
	while(i < slen && j < plen)
	{
		if(j == -1 || src[i] == patn[j])
		{
			++i;
			++j;
		}else
			j = nextval[j];
	}
	if(j >= plen)
		return i - plen;
	else
		return -1;
}
void get_nextval(char const *ptrn, int plen, int *nextval)
{
	int i = 0; 
	nextval[i] = -1;
	int j = -1;
	while(i < plen - 1)
	{
		if(j == -1 || ptrn[i] == ptrn[j])
		{
			++i;
			++j;
			nextval[i] = j;
		}else
			j = nextval[j];
	}
}
int main(int argc, char *argv[])
{
	return 0;
}

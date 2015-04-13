/*************************************************************************
    > File Name: reverse_bits.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Fri 10 Apr 2015 11:54:17 PM PDT
 ************************************************************************/

#include<iostream>
#include<stdint.h>
#include<bitset>
using namespace std;

uint32_t reverseBits(uint32_t n)
{
	bitset<32> bs(n);
	cout << bs << endl;
	string s = bs.to_string();
	for( int i = 0; i < s.length()/2; ++i)
	{
		char temp = s[i];
		s[i] = s[s.length() - 1 - i];
		s[s.length() - 1 - i] = temp;
	}
	bitset<32> bs2(s);
	return bs2.to_ulong();
}
int main(int argc, char *argv[])
{
	uint32_t i = 43261596;
	cout << reverseBits(i) << endl;
	return 0;
}

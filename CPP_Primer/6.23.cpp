/*************************************************************************
    > File Name: 6.23.cpp
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Tue 21 Apr 2015 04:03:33 PM CST
 ************************************************************************/

#include<iostream>
#include<bitset>
#include<stdexcept>
using namespace std;

int main(int argc, char *argv[])
{
	bitset<100> bs;
	for(size_t ix = 0; ix != bs.size(); ++ix)
		bs[ix] = 1;
	try{
		unsigned long ul = bs.to_ulong();
	}catch(overflow_error err)
	{
		cout << err.what() << endl;
	}
	return 0;
}

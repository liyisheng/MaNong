/*************************************************************************
    > File Name: 9.7.1.cpp
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Thu 23 Apr 2015 03:42:40 PM CST
 ************************************************************************/

#include<iostream>
#include<stack>
using namespace std;

int main(int argc, char *argv[])
{
	const stack<int>::size_type stk_size = 10;
	stack<int> intStack;

	int ix = 0;

	while(intStack.size() != stk_size)
		intStack.push(ix++);

	int error_cnt = 0;
	while(intStack.empty() == false)
	{
		int value = intStack.top();
		if(value != -ix)	
		{
			cerr << "oops! expected " << ix
				<< "received " << value << endl;
		}
		intStack.pop();
	}
	return 0;
}

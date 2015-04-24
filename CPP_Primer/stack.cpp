/*************************************************************************
    > File Name: stack.cpp
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Thu 23 Apr 2015 03:35:22 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<deque>
#include<stack>
using namespace std;

int main(int argc, char *argv[])
{
	vector<int> ivec;
	for(int i = 0 ; i != 10; ++i)
		ivec.push_back(i);

	deque<int> ideq;
	for(int i = 0 ; i != 10; ++i)
		ideq.push_back(i);

	stack<int> stk(ideq);

	stack<int, vector<int> > vstk(ivec);
	return 0;
}

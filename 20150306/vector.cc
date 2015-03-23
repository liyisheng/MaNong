/*************************************************************************
    > File Name: vector.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Sun 08 Mar 2015 04:14:41 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(int argc, char *argv[])
{
	const int kMax = 5;
	vector<int> vec;
	for(int idx = 0; idx != kMax; ++idx)
	{
		vec.push_back(idx);
	}

	vector<int>::iterator it = vec.begin();
	for(; it != vec.end(); ++it)
	{
		cout << *it << endl;
	}
	cout << endl;
	cout << vec.capacity() <<endl;
	cout << vec.size() << endl;

	vec.push_back(5);
	vec.push_back(6);
	vec.push_back(7);

	cout << vec.capacity() << endl;
	cout << vec.size() << endl;


	return 0;
}

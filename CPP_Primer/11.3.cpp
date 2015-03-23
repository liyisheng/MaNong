/*************************************************************************
    > File Name: 11.3.cpp
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Mon 16 Mar 2015 09:29:27 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int main(int argc, char *argv[])
{
	vector<int> ivec;
	for(int i = 0; i < 10; ++i)
		ivec.push_back(i);
	
	int sum = accumulate(ivec.begin(), ivec.end(), 0);	
	cout << sum << endl;

	return 0;
}

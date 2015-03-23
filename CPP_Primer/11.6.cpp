/*************************************************************************
    > File Name: 11.6.cpp
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Mon 16 Mar 2015 09:49:33 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(int argc, char *argv[])
{
	vector<int> ivec;
	ivec.resize(10);
	fill_n(ivec.begin(), 10, 1);

	for(int i = 0; i != ivec.size(); ++i)
		cout << ivec[i] << endl;
	return 0;
}

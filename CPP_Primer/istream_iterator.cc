/*************************************************************************
    > File Name: istream_iterator.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Tue 17 Mar 2015 04:07:26 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<iterator>
using namespace std;

int main(int argc, char *argv[])
{
	istream_iterator<int> in_iter(cin);	
	istream_iterator<int> eof;
	vector<int> vec(in_iter, eof);
	for(int i = 0; i != vec.size(); ++i)
		cout << vec[i] << endl;

	return 0;
}

/*************************************************************************
    > File Name: stream_iterator.cpp
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: 2015年04月26日 星期日 19时10分56秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;

int main(int argc, char *argv[])
{
	istream_iterator<int> cin_it(cin), eof;
	vector<int> ivec(cin_it, eof);

	sort(ivec.begin(), ivec.end());

	ostream_iterator<int> output(cout, " ");
	unique_copy(ivec.begin(), ivec.end(), output);
	return 0;
}

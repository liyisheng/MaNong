/*************************************************************************
    > File Name: ostream_iterator.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Tue 17 Mar 2015 04:11:37 PM CST
 ************************************************************************/

#include<iostream>
#include<iterator>

using namespace std;

int main(int argc, char *argv[])
{
	ostream_iterator<string> out_iter(cout, "\n");
	istream_iterator<string> in_iter(cin) , eof;
	while(in_iter != eof)
		*out_iter++ = *in_iter++;
	return 0;
}

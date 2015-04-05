/*************************************************************************
    > File Name: fact_trailingZeroes.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Mon 23 Mar 2015 04:36:06 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int trailingZeroes(int n) {

	int count = 0;
	int x = 5;
	while( n >= x)
	{
		count += n/x;
		x *= 5;
	}
	return count;
}
int main(int argc, char *argv[])
{
	cout << trailingZeroes(125) << endl;
	return 0;
}

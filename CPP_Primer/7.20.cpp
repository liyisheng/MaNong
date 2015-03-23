/*************************************************************************
    > File Name: 7.20.cpp
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Wed 18 Mar 2015 01:26:07 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int factorial(int val)
{
	if(val > 0)
		return factorial(val - 1) * val;
	return 1;
}
int factorial(int val, int nul)
{
	int sum = 1;
	for(; nul != val + 1; ++nul)	
		sum *= nul;
	return sum;
}


int main(int argc, char *argv[])
{
	cout << factorial(5, 1) << endl;
	cout << factorial(-5) << endl;
	return 0;
}

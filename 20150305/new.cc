/*************************************************************************
    > File Name: new.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Fri 06 Mar 2015 11:13:04 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int main(int argc, char *argv[])
{
	int *pval = new int(3);
	std::cout << "*pval = " << *pval << std::endl;

	int *pval2 = new int[10];

	delete pval;
	delete []pval2;

	return 0;
}

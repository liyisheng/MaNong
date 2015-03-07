/*************************************************************************
    > File Name: const.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Fri 06 Mar 2015 07:17:22 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int main(int argc, char *argv[])
{
	const int ival; //Error, must be initialized
	const int ival = 10;

	const int *pival = &ival;
	std::cout <<"*pival = "<< *pival << std::endl;


	int ival2 = 20;
	int *const pival2 = &ival2;

	int ival3 = 30;

	int ival4 = 40;
	const int *const pival4 = &ival4;

	int ival5 = 50;

	*pival4 = 60;
	pival4 = &ival3;
	return 0
}

/*************************************************************************
    > File Name: cast.cpp
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Fri 06 Mar 2015 05:31:16 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int test0()
{
	int ival = static_cast<int>(3.14159);

}


int main()
{
	const int ival = 10;
	
//	int *t = &ival;  //error
//	*t = 20;	
	int *pival = const_cast<int*>(&ival);
	*pival = 20;

	std::cout << "*pival = " << *pival << std::endl;
	std::cout << "*ival = " << ival << std::endl;
}

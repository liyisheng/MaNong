/*************************************************************************
    > File Name: namespace.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Fri 06 Mar 2015 11:07:07 PM CST
 ************************************************************************/

#include<iostream>
//using namespace std;

int ival = 100;

namespace mynm
{
	int ival2 = 20;
	int ival3;
	double dval;

	int max(int a, int b)
	{
		return a > b ? a : b;
	}
}

int main(int argc, char *argv[])
{

	int ival = 10;
	std::cout << "Hello, world!" << std::endl;
	std::cout << "main->ival = " << ival << std::endl;
	std::cout << "::ival = " << ::ival << std::endl;

	std::cout << "ival2 = " << mynm::ival2 << std::endl;
	std::cout << "max(3,4)" << mynm::max(3,4) << std::endl;
	std::cout << "ival3 = " << mynm::ival3 << std::endl;
	
	std::cout << "dval =" << mynm::dval << std::endl;
	return 0;
}

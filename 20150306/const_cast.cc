/*************************************************************************
    > File Name: const_cast.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Sat 07 Mar 2015 09:23:35 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

void printer(int *pa)
{
	std::cout << "*pa = " << *pa << std::endl;
}


int main(int argc, char *argv[])
{
	const int ival = 10;
	int *pival = const_cast<int*>(&ival);

//	int ival2 = const_cast<int>(ival);  //error
	cout << "*pival = "	 << *pival << endl;
	*pival = 20;

	cout << "*pival = "  << *pival << endl;
	cout << "ival ="  << ival << endl;
	cout << "pival =" << pival << endl;
	cout << "&ival =" << &ival << endl;

	printer(const_cast<int *>(&ival));
	return 0;
}

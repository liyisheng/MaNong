/*************************************************************************
    > File Name: function.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Fri 06 Mar 2015 09:40:13 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int add(int a, int b)
{
	return a + b;
}

double add(double a, double b)
{
	return a + b;
}

inline int max(int a, int b)
{
	return a > b ? a : b;
}

#ifdef __cplusplus
extern "C"  //这中间的代码用C编译器编译
{
#endif

int fun(int a, int b)
{
	return a + b;
}

#ifdef __cplusplus
}
#endif

int main(int argc, char *argv[])
{

	std::cout << " add (3, 4) = " << add(3,4) <<std::endl;
	std::cout << " add (3.3, 4.4) = " << add(3.3,4.4) <<std::endl;
	std::cout << " add (3, 4) = " << fun(3,4) <<std::endl;
	return 0;
}


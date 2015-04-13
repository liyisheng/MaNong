/*************************************************************************
    > File Name: reverse_integer.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Wed 08 Apr 2015 08:58:40 AM PDT
 ************************************************************************/

#include<iostream>
#include<limits.h>
using namespace std;

int reverse(int x)
{
	int flag = 1;
	if(x == 0 || x == INT_MIN)
		return 0; 
	if(x < 0)	
	{
		flag = -1;
		x *= -1;
	}
	long long res = 0;
	while(x)
	{
		res = res*10 + x%10;
		x /= 10;
	}
	if(res > INT_MAX)
		return 0;
	else
		return res*flag;
}

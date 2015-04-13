/*************************************************************************
    > File Name: 1.15.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Thu 09 Apr 2015 11:43:57 PM PDT
 ************************************************************************/
/*input: 一个长度为n的整数数组input:
 *output: 一个长度为n的整数数组result，满足result[i] = input数组中除了input[i]之外所有
 *数的乘积(假设不会溢出).
 */
#include<iostream>
using namespace std;
/*
int *cal(int *input, int n)
{
	int *result = new int[n];
	for(int i = 0; i < n; ++i)
	{
		result[i] = 1;
		for(int j = 0; j < n; ++j)
		{
			if(j == i)
				continue;
			result[i] *= input[j]; 
		}
	}
	return result;
}
*/

//时间复杂度O(n)的写法
int *cal(int *input, int n)
{
	int i;
	int *result = new int[n];
	result[0] = 1;
	for(int i = 1; i < n; ++i)
		result[i] = result[i - 1] * input[i - 1];
	result[0] = input[n - 1];

	for(int i = n - 2; i > 0; --i)
	{
		result[i] *= result[0];
		result[0] *= input[i];
	}
}
int main(int argc, char *argv[])
{
	int input[4] = {
		2, 3, 4, 5
	};
	int *a = cal(input, 4);
	for(int i = 0; i < 4; ++i)
		cout << *a++ << " ";
	return 0;
}

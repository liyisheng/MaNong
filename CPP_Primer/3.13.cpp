/*************************************************************************
    > File Name: 3.11.cpp
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Sat 14 Mar 2015 09:15:33 PM CST
 ************************************************************************/
/*
 *读一组整数到vector对象，计算并输出每对相邻元素的和。 如果读入元素个数为奇数，则提示用户最后
 *一个元素没有求和，并输出其值。然后修改程序：头尾元素两两配对，计算每对元素的和，并输出 
 */
#include<iostream>
#include<vector>
using namespace std;

int main(int argc, char *argv[])
{

	vector<int> ivec;
	int n;
	while(cin >> n)
	{
		ivec.push_back(n);
	}
	vector<int>::size_type i;
	vector<int>::size_type j;
	for(i = 0, j = ivec.size() - 1; i < j; ++i, --j)
	{
		cout << ivec[i] + ivec[j] << " ";
	}
	cout << endl;
	if(i == j)
	{
		cout << "输入元素个数为奇数,中间数为" <<endl;
		cout << ivec[i] << endl;
	}
	return 0;
}

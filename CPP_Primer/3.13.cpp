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
	int i;
	for(i = 0; i < ivec.size() - 1; i+=2)
	{
		cout << ivec[i] + ivec[i + 1] << " ";
	}
	cout << endl;
	if(i != ivec.size())
	{
		cout << "输入元素个数为奇数,最后一个数为" <<endl;
		cout << ivec[ivec.size() - 1] << endl;
	}
	return 0;
}

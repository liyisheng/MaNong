/*************************************************************************
    > File Name: 1.19.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Fri 10 Apr 2015 01:07:41 AM PDT
 ************************************************************************/
/*数组中有一个数字出现的次数超过了数组长度的一半，请找出这个数字
 * */
#include<iostream>
using namespace std;

int function(int data[], int length)
{
	int currentAxis;
	int currentNum = 1;
	for(int i = 0; i < length; ++i)
	{
		if(currentNum == 0)
		{
			currentAxis = data[i];
			currentNum = 1;
		}else
		{
			if(currentAxis == data[i])
				currentNum ++;
			else
				currentNum --;
		}
	}
	return currentAxis;
}

int main(int argc, char *argv[])
{
	int a[10] = {
		2,2,2,2,2,2, 3, 3, 3, 3
	};
	cout << function(a, 10);
	return 0;
}

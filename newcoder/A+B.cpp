/*************************************************************************
    > File Name: A+B.cpp
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Mon 18 May 2015 03:31:11 PM CST
 ************************************************************************/


#include<iostream>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;

	int sum = a + b;
	bool flag = true;	
	if(sum < 0)
	{
		flag = false; 
		sum = -sum;
	}
	int count = 0;
	string s;
	while(sum)
	{
		if(count == 3)
		{
			s.insert(0, 1, ',');	
			count = 0;
		}else
		{
			s.insert(0, 1, sum % 10 + '0');
			count++;
			sum /= 10;
		}
	}
	if(!flag)
		s.insert(0, 1, '-');
	cout << s << endl;
}


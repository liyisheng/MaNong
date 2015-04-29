/*************************************************************************
    > File Name: class.cpp
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: 2015年04月26日 星期日 22时42分59秒
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;


class A
{
	public:
		static int getA()
		{
			return a;
		}
		const static int a = 88; 
};

//const int A::a;
int main(int argc, char *argv[])
{
	cout << A::a << endl;
	cout << min(9, (int)A::a);
	return 0;
}

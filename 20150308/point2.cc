/*************************************************************************
    > File Name: point.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Sun 08 Mar 2015 08:48:43 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class Point
{
	public:
		Point(int x = 0, int y = 0)// explicit 只能显式调用
		{
			cout << "调用构造函数"<< endl;
			ix = x;
			iy = y;
		}
		Point() : ix(0), iy(0){

		}
		
		Point(const Point &rhs)
		{
			cout << "调用复制构造函数" << endl;
			ix = rhs.ix;
			iy = rhs.iy;
		}

		void print()
		{
			cout << "(" << ix << "," << iy << ")" << endl;
		}
	private:
		int ix;
		int iy;
};

int main()
{
	Point pt1 = 1; //隐式转换
	pt1.print();

	return 0;
}

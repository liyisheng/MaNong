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
		Point(int x = 0, int y = 0)
		{
			cout << "调用构造函数"<< endl;
			ix = x;
			iy = y;
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

int main(int argc, char *argv[])
{
	Point pt1(3, 4);
	pt1.print();
	
	Point pt2 = pt1;
	pt2.print();

	Point pt3;
	pt3.print();

	Point pt4(pt1);
	pt4.print();

	return 0;
}

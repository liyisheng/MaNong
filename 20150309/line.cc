/*************************************************************************
    > File Name: line.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Mon 09 Mar 2015 10:38:09 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class Point
{
	public:
		Point(int ix, int iy)
		{
			ix_ = ix;
			iy_ = iy;
		}
		
		Point(const Point &rhs)
		{
			cout << "点的复制构造函数被调用"<< endl;
			ix_ = rhs.ix_;
			iy_ = rhs.iy_;
		}

		void print()
		{
			cout << "(" << ix_ << "," << iy_ << ")" << endl;
		}

	private:
		int ix_;
		int iy_;
}

class Line
{
	public:
		Line(int x1, int y1, int x2, int y2)
			: pt1_(x1, y1), pt2(x2, y2)
		{
			cout << "线的构造函数被运行" << endl;
		}

		Line(const Line &rhs) : pt1_(rhs.pt1_), pt2(rhs.pt2_)
		{

			cout << "线的复制构造函数被运行" << endl;
		}

		void draw()
		{
			pt1_.print();
			cout << " to ";
			pt2_.print();
			cout << endl;
		}

		Point getPoint()
		{
			return  pt1_;
		}
	private:
		Point pt1_;
		Point pt2_;

}

int main(int argc, char *argv[])
{
	Line line1(1,2,3,4);
	return 0;
}

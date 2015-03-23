/*************************************************************************
    > File Name: const_overload.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Tue 10 Mar 2015 09:27:20 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class Screen
{
	public:
		Screen(int x = 0, int y = 0) : x(x), y(y){}
		Screen & display(ostream &os)
		{
			os << "display  " << x << "  "<< y;
			return *this;
		}
		const Screen & display(ostream &os) const
		{
			os << "const display  "<< x << "  "<< y;
			return *this;
		}
		Screen & setx(int x)
		{
			this->x = x;
		}
	public:
		int x;
		int y;

};

int main(int argc, char *argv[])
{
	Screen m(1, 2);
	const Screen b(1,3);
	m.display(cout).setx(2).display(cout);
	cout << endl;
	b.display(cout);
	cout << endl;

	return 0;
}

/*************************************************************************
    > File Name: Singleton.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Fri 20 Mar 2015 10:28:27 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class CA
{
	private:
		static CA *pA;
		int x;
		int y;
		CA(int x = 0, int y = 0)
		{
			this ->x = x;
			this ->y = y;
		}
	public:
		static CA* GetInstance(int x = 0, int y = 0)
		{
			if(NULL == pA)
			{
				pA = new CA(x, y);
			}
		}
		void disp() const
		{
			cout << "(" << this ->x << "," << this ->y << ")" << endl;
		}
};
CA* CA::pA = NULL;
int main(int argc, char *argv[])
{
	CA *p1 = CA::GetInstance(3,4);
	CA *p2 = CA::GetInstance(1,2);
	CA *p3 = CA::GetInstance(5,6);

	cout << p1 << endl;
	cout << p2 << endl;
	cout << p3 << endl;

	p1 ->disp();
	p2 ->disp();
	p3 ->disp();

	return 0;
}

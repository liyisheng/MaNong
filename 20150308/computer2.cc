/*************************************************************************
    > File Name: computer.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Sun 08 Mar 2015 05:17:16 PM CST
 ************************************************************************/

#include<iostream>
#include<string.h>

using namespace std;

class Computer
{
	public:
		Computer(const char *brand, float price)
		{
			psBrand_ = new char[strlen(brand) + 1];
			strcpy(psBrand_, brand);
			fPrice_ = price;
		}
		Computer(): psBrand_(NULL), fPrice_(0.0){}

		~Computer()
		{
			if(psBrand_)
			{
				delete[] psBrand_;
				psBrand_ = NULL;
			}
			cout << "清理现场" << endl;
		}

		void print()
		{
			cout << "品牌 : " << psBrand_ << endl;
			cout << "价格： " << fPrice_ << endl;
		}

		Computer(const Computer &rhs)
		{
			psBrand_ = new char[strlen(rhs.psBrand_) + 1];
			if(psBrand_ == NULL)
			{
				cout << "memory allocated fail " << endl;
				return;
			}
			strcpy(psBrand_, rhs.psBrand_);
			fPrice_ = rhs.fPrice_;
		}
	private:

	private:
		char *psBrand_;
		float fPrice_;
};


int main(int argc, char *argv[])
{
	Computer pc1("Dell",  7000);
	pc1.print();

	Computer pc2 = pc1;
	pc2.print();
	return 0;
}

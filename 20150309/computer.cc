/*************************************************************************
    > File Name: computer.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Mon 09 Mar 2015 07:28:05 PM CST
 ************************************************************************/

#include<iostream>
#include<string.h>

using namespace std;

class Computer
{
	public:
		Computer(const char *brand,  float price)
		{
			psBrand_ = new char[strlen(brand) + 1];
			strcpy(psBrand_, brand);
			fPrice_ = price;
		}
		Computer() : psBrand_(NULL), fPrice_(0.0){}

		~Computer()
		{
			cout << psBrand_ << "清理现场" << endl;
			delete[] psBrand_;
			psBrand_ = NULL;
		}
		void print()
		{
			cout << "品牌 : " << psBrand_ << endl;
			cout << "价格 : " << fPrice_ << endl;
		}
	private:
		char *psBrand_;
		float fPrice_;
};

Computer pc("Acer", 5000);

int main(int argc, char *argv[])
{
	{
		Computer pc1("Dell", 7000);
		pc1.print();
		pc1.~Computer();
		cout << endl;
	}

	Computer *pc3 = new Computer("Mac", 10000);

	pc3 -> print();
	delete pc3;

	pc.print();
	return 0;
}

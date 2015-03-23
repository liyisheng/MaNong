/*************************************************************************
    > File Name: computer3.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Sun 08 Mar 2015 08:05:46 PM CST
 ************************************************************************/

#include<iostream>
#include<string.h>
using namespace std;

class Computer
{
	public:
		Computer() : psBrand(NULL), fPrice(0.0){}

		bool init(const char *brand, float price)
		{
			if(NULL == brand)
			{
				cout <<"pramater error" <<endl;
				return false;
			}
			psBrand = new char[strlen(brand) + 1];
			if(NULL == psBrand)
			{
				cout << "memory allocated fail" << endl;
				return false;
			}
			strcpy(psBrand, brand);
			fPrice = price;

			return true;
		}

		~Computer()
		{
			if(psBrand)
			{
				delete[] psBrand;
				psBrand = NULL;
			}
			cout <<  "清理现场" << endl;
		}

		void print()
		{
			cout << "品牌" << psBrand << endl;
			cout << "价格" << fPrice << endl;
		}

		Computer(const Computer &rhs)
		{
			psBrand = new char[strlen(rhs.psBrand) + 1];
			if(psBrand == NULL)
			{
				cout << "memory allocated fail" << endl;
				return ;
			}
			strcpy(psBrand, rhs.psBrand);
			fPrice = rhs.fPrice;
		}
	private:
		char *psBrand;
		float fPrice;
};;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

int main(int argc, char *argv[])
{
	Computer pc;
	bool ret = pc.init("Dell", 7000);
	if(ret == false)
	{
		cout << "computer init error" << endl;
	}
	pc.print();

	return 0;
}

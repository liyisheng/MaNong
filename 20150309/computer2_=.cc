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
			fTotalPrice_ += fPrice_;
		}
		Computer() : psBrand_(NULL), fPrice_(0.0){}

		Computer(const Computer &rhs)
		{
			psBrand_ = new char[strlen(rhs.psBrand_) + 1];
			if(NULL == psBrand_)
			{
				cout << "memory allocated fail" << endl;
				return;
			}
			strcpy(psBrand_, rhs.psBrand_);
			fPrice_ = rhs.fPrice_;
		}

		Computer &operator=(const Computer &rhs)
		{
			if(this ==  &rhs)
			{
				return (*this);
			}
			if(psBrand_)
			{
				delete[] psBrand_;
				psBrand_ = NULL;
			}//防止内存泄露

			psBrand_ = new char[strlen(rhs.psBrand_) + 1];
			if(NULL == psBrand_)
			{
				cout << "memory allocated fail" << endl;
				return (*this);
			}

			strcpy(psBrand_, rhs.psBrand_);
			fPrice_ = rhs.fPrice_;

			cout << "赋值运算符函数被调用" <<endl;
			return (*this);
		}

		~Computer()
		{
			delete[] psBrand_;
			psBrand_ = NULL;
			cout << "清理现场" << endl;
		}
		void print()
		{
			cout << "品牌 : " << psBrand_ << endl;
			cout << "价格 : " << fPrice_ << endl;
		}

		static void print_total()
		{
			cout << " 总价： "<< fTotalPrice_ << endl;
		}

		static void print(Computer &com);
	private:
		char *psBrand_;
		float fPrice_;
		static float fTotalPrice_;
};
float Computer:: fTotalPrice_ = 0.0;
void Computer::print(Computer &com)
{
	cout << "名称: " << com.psBrand_ << endl;
	cout << "价格：" << com.fPrice_ << endl;
}



int main(int argc, char *argv[])
{
	Computer pc("IBM", 7000);
	pc.print(pc);
	pc.print_total();

	cout << endl;

	Computer pc2("Mac", 10000);
	Computer::print(pc2);
	pc2.print_total();

	cout << endl;

	Computer pc4(pc2);
	Computer::print(pc4);
	pc4.print_total();

	Computer pc3;
	pc3 = pc2;
	cout << "pc3 ::" << endl;
	pc3.print(pc3);
	pc3.print_total();

	return 0;
}

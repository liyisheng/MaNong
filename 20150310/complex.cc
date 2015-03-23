/*************************************************************************
    > File Name: complex.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Tue 10 Mar 2015 06:50:51 PM CST
 ************************************************************************/

#include<iostream>

using namespace std;

class complex
{
	private:
		double real;
		double imag;
	public:
		complex(double r = 0.0, double i = 0.0)
		{
			real = r;
			imag = i;
		}
		complex& operator+=(const complex &);
		complex operator+(const complex &);
		complex operator-(const complex &);
		complex operator-();
		complex operator*(const complex &);
		complex operator/(const complex &);

		complex &operator++();
		complex operator++(int);
		
		void disp()
		{
			cout << real << "+ i*" << imag << endl;
		}

};

complex &
complex::operator+=(const complex &CC)
{
	real += CC.real;
	imag += CC.imag;
	return (*this);
}

complex complex::operator+(const complex &CC)
{
	return complex(real + CC.real, imag + CC.imag);
}

complex complex::operator-(const complex &CC)
{
	return complex(real - CC.real, imag - CC.imag);
}

complex complex::operator-()
{
	return complex(-real, -imag);
}

complex & complex::operator++()
{
//	cout<<"前置++"<<endl;
	++real;
	++imag;
	return *this;
}

complex complex::operator++(int)
{
	cout<<"后置++" << endl;
	complex temp = (*this);
	++(*this);
	
	return temp;
}

int main(int argc, char *argv[])
{
	complex cx1(1.0,2.0), cx2(3.0, 4.0), cxRes;
	cxRes += cx2;
	cxRes.disp();
	
	cxRes = cx2++;
	cxRes.disp();

	return 0;
}

/*************************************************************************
    > File Name: complex.h
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Sat 02 May 2015 10:21:49 PM CST
 ************************************************************************/

#ifndef _COMPLEX_H
#define _COMPLEX_H

#include<iostream>
class Complex
{
//	friend Complex operator+(const Complex&, const Complex&);
	friend Complex operator -(const Complex&, const Complex&);
	friend Complex operator*(const Complex&, const Complex&);
	friend Complex operator/(const Complex&, const Complex&);
	friend std::ostream& operator<<(std::ostream &os, const Complex &rhs);
	friend std::istream& operator>>(std::istream &is,Complex &rhs);
	public:
		Complex(double r = 0.0, double i = 0.0) :
			real(r), imag(i){ }

		Complex& operator+=(const Complex&);
	private:
		double real;
		double imag;
};

Complex operator+(const Complex&, const Complex&);
#endif

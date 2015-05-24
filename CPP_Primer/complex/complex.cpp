/*************************************************************************
    > File Name: complex.cpp
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Sat 02 May 2015 10:47:31 PM CST
 ************************************************************************/

#include"complex.h"

Complex& Complex::operator+=(const Complex &rhs)
{
	this ->real += rhs.real;
	this ->imag += rhs.imag;
	return *this;
}

Complex operator+(const Complex &lhs, const Complex &rhs)
{
	Complex ret(lhs);
	ret += rhs;
	return ret;
}

Complex operator-(const Complex &lhs, const Complex &rhs)
{
	Complex ret(lhs.real - rhs.real, lhs.imag - rhs.imag);
	return ret; 
}

Complex operator*(const Complex &lhs, const Complex &rhs)
{
	Complex ret(lhs.real * rhs.real - lhs.imag * rhs.imag, \
			lhs.real * rhs.imag + lhs.imag * rhs.real);
	return ret;
}

Complex operator/(const Complex &lhs, const Complex &rhs)
{
	Complex ret((lhs.real * rhs.real + lhs.imag * rhs.imag)/
			(rhs.real * rhs.real + rhs.imag * rhs.imag),
			(lhs.imag * rhs.real - lhs.real * rhs.imag)/
			(rhs.real * rhs.real + rhs.imag * rhs.imag));
}

std::ostream& operator<<(std::ostream &os, const Complex &rhs)
{
	if(rhs.imag > 0)
		os << rhs.real << "+" << rhs.imag << "i";
	else if(rhs.imag < 0)
		os << rhs.real << rhs.imag << "i";
	else
		os << rhs.real;
}

std::istream& operator>>(std::istream &is, Complex &rhs)
{
	std::cout << "请输入复数格式(A+Bi)" << std::endl;
	is >> rhs.real;
	while(is.get() != '+')
		;
	is >> rhs.imag;
}


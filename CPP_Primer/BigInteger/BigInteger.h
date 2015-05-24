/*************************************************************************
    > File Name: BigInteger.h
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Mon 04 May 2015 11:25:21 AM CST
 ************************************************************************/

#ifndef _BIGINTEGER_H
#define _BIGINTEGER_H

#include<iostream>
class BigInteger
{
	
	friend BigInteger operator +(const BigInteger&, const BigInteger&);
	friend BigInteger operator -(const BigInteger&, const BigInteger&);
	friend BigInteger operator *(const BigInteger&, const BigInteger&);
	friend BigInteger operator /(const BigInteger&, const BigInteger&);
	friend std::ostream& operator <<(std::ostream &, const BigInteger&);
	friend std::istream& operator >>(std::istream &, BigInteger&);
	public:
		BigInteger(const std::string &str = "") :
			num(str){ }
		BigInteger& operator +=(const BigInteger&);
	private:
		std::string num;
};
#endif

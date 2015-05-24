/*************************************************************************
    > File Name: BigInteger.cpp
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Mon 04 May 2015 11:30:19 AM CST
 ************************************************************************/

#include"BigInteger.h"
#include<string>
using namespace std;
BigInteger& BigInteger::operator+=(const BigInteger& rhs)
{
	*this = *this + rhs;
	return *this;
}

BigInteger operator+(const BigInteger &lhs, const BigInteger &rhs)
{
	string str_long;	
	string str_short;
	lhs.num.size() > rhs.num.size() ? (str_long = lhs.num,str_short = rhs.num) : (str_long = rhs.num, str_short = lhs.num);

	if(str_long[0] == '-')
		str_long = str_long.substr(1);
	if(str_short[0] == '-')
		str_short = str_short.substr(1);
	for(string::size_type i = 0; i != str_long.size(); ++i)
		str_long[i] -= '0';
	
	for(string::size_type i = 0,j = str_long.size() - str_short.size(); j != str_long.size(); ++i,++j)
	{
		str_long[j] = str_long[j] + str_short[i] - '0';
	}

	for(string::size_type i = str_long.size() - 1; i > 0; --i)
	{
		if(str_long[i] >= 10)
		{
			str_long[i - 1] ++;
			str_long[i] %= 10;
		}
	}

	if(str_long[0] >= 10)
	{
		str_long[0] %= 10;
		str_long.insert(0, 1, '1');
	}

	for(string::size_type i = 0; i != str_long.size(); ++i)
		str_long[i] += '0';

	return BigInteger(str_long);

}

BigInteger operator -(const BigInteger &lhs, const BigInteger &rhs)
{
	
}

ostream &operator << (ostream &os, const BigInteger &rhs)
{
	os << rhs.num;
}

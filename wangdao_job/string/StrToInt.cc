/*************************************************************************
    > File Name: StrToInt.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Fri 10 Apr 2015 06:56:05 AM PDT
 ************************************************************************/

#include<iostream>
#include<limits>
using namespace std;

int StrToInt(const char *str)
{
	long long num = 0;
	if(str != NULL)
	{
		const char *digit = str;
		bool minus = false;
		if(*digit == '+')
			digit ++;
		else if(*digit == '-')
		{
			digit ++;
			minus = true;
		}
		while(*digit != '\0')
		{
			if(*digit >= '0' && *digit <= '9')
			{
				num = num * 10 + (*digit - '0');
				if(num > numeric_limits<int>::max())
				{
					num = 0;
					break;
				}
				digit ++;
			}else
			{
				num = 0;
				break;
			}
		}
		if(*digit == '\0')
		{
			if(minus)
				num = 0 - num;
		}
	}
	return num;
}

int main(int argc, char *argv[])
{
	string a = "12345";
	cout << StrToInt(a.c_str()) << endl;
	return 0;
}

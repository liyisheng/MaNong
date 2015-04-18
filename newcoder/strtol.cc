/*************************************************************************
    > File Name: strtol.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Mon 13 Apr 2015 10:02:43 PM PDT
 ************************************************************************/

#include<iostream>
#include<limits>
using namespace std;

int strtol(const char *num_str, char **endptr, int base)
{
	long long num = 0;
	bool negative = false;	
	const char *a = num_str;
	int base2;
	switch(base)
	{
		case 0:
			if(*num_str == '0')
			{
				base2 = 8;
				a++;
				if(*(num_str + 1) == 'x' || *(num_str + 1) == 'X')
				{
					base2 = 16;
					a++;
				}
			}else
			{
				base = 10;
				if(*num_str == '-')
				{
					negative = true;
					a++;
				}
			}
			break;
		default:
			base2 = base;
	}
	while( *a != '\0')
	{
		if( (*a >= '0' && *a <= '9') || (*a >= 'A' && *a <= 'F'))
		{
			num = num * base2 + (isalpha(*a) ? (*a - 'A' + 10) : (*a - '0'));	
			if(num > numeric_limits<int>::max() && !negative)
				return numeric_limits<int>::max();
			else if( (0 - num) < numeric_limits<int>::min() && negative)
				return numeric_limits<int>::min();
			a++;
		}else
		{
			if(endptr != NULL)
				*endptr =  const_cast<char *>(a);
		}
	}
	if(negative)
		return (0 - num);
	return num;
}


int main(int argc, char *argv[])
{
	char *endptr;
	cout << strtol("0xFF1100", &endptr, 0) << endl; return 0;
}

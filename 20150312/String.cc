#include <stdio.h>
#include <iostream>
#include <string.h>

class String
{
	public:
		String(const char *str = NULL);
		String(const String &rhs);
		String& operator=(const String &rhs);
		~String();

		char& operator [](int idx);
		String &operator +=(const String &rhs);

		std::size_t size()const
		{
			return strlen(pStr_);
		}

		const char *c_str() const
		{
			return pStr_;
		}

		friend std::ostream &operator <<(std::ostream &os, const String &rhs);
	private:
		char *pStr_;
};

String operator +(const String &lhs, const String &rhs);

String::String(const char *str)
{
	if(NULL == str)
	{
		pStr_ = new char[2];
		pStr_[0] = '\0';
		pStr_[1] = 1;
		return;
	}

	int len = strlen(str);
	pStr_ = new char[len + 2];
	strncpy(pStr_, str, len);
	pStr_[len + 1] = 1;
}

String::String(const String &rhs)
{
	if(this != &rhs)
	{
		pStr_ = rhs.pStr_;
		int len = strlen(pStr_);
		++pStr_[len + 1]; 
	}
}

String &String::operator =(const String &rhs)
{
	if(this != &rhs)
	{
		int len = strlen(pStr_);
		--pStr_[len + 1];

		pStr_ = rhs.pStr_;
		len = strlen(pStr_);
		++pStr_[len + 1];
	}
	return *this;
}

String::~String()
{
	int len = strlen(pStr_);
	--pStr_[len +1];
	if(0 == pStr_[len + 1])
		delete [] pStr_;
}

char &String::operator [](int idx)
{
	int len = strlen(pStr_);
	if(idx > len || len == 0)
	{
		static char nullchar = '\0';
		return nullchar;
	}
	if(pStr_[len + 1] > 0)
	{
		char *pbuf = new char[len + 2];
		strncpy(pbuf, pStr_, len);
		--pStr_[len + 1];
		pStr_ = pbuf;
		pStr_[len + 1] = 1;
	}
	return pStr_[idx];
}

std::ostream &operator <<(std::ostream &os, const String &rhs)
{
	os << rhs.pStr_;
}

int main(void)
{
	String s1 = "hello";
	std::cout << s1 << std::endl;
	std::cout << "s1.size() = " << s1.size() <<"  " << (int)s1[6] <<  std::endl;
	printf("s1's address: %x\n", s1.c_str());

	String s2 = s1;
	std::cout << s2 << std::endl;
	std::cout << "s2.size() = " << s2.size() << "  " << (int)s2[6]<< std::endl;
	printf("s2's address: %x\n", s2.c_str());

	String s3;
	s3 = s1;
	std::cout << s3 << std::endl;
	std::cout << "s3.size() = " << s3.size() <<"  " << (int)s3[6]<< std::endl;
	printf("s3's address: %x\n", s3.c_str());

	s3[1] = 'w';

	std::cout << s3 << std::endl;
	std::cout << "s3.size() = " << s3.size() << "   " << (int )s3[6]<< std::endl;
	printf("s3's address: %x\n", s3.c_str());

	std::cout << s1 << std::endl;
	std::cout << "s1.size() = " << s1.size() << std::endl;
	printf("s1's address: %x\n", s1.c_str());
	std::cout << s2 << std::endl;
	std::cout << "s2.size() = " << s2.size() << std::endl;
	printf("s2's address: %x\n", s2.c_str());
}

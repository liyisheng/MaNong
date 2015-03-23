/*************************************************************************
    > File Name: String.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Tue 10 Mar 2015 10:48:18 AM CST
 ************************************************************************/

#include<iostream>
//using namespace std;

class String
{
	public:
		String(const char *str = NULL);
		String(const String &another);
		~String();
		String &operator=(const String &rhs);
	private:
		char *m_data;
};

String::String(const char *str);
{
	m_data = NULL;
}

String::String(const String &another)
{
	m_data = new char[strlen(another.m_data) + 1];
	strcpy(m_data, another.m_data);
}

String & String::operator=(const String &rhs)
{
	if(this == &ths)
		return *this;
	if(m_data)
	{
		delete[]  m_data;
		m_data = NULL;
	}

	m_data = new char[strlen(rhs.m_data) + 1];
	strcpy(m_data, rhs.m_data);

	return *this;
}

String::~String()
{
	delete[] m_data;
	m_data = NULL;
}

int main(int argc, char *argv[])
{
	return 0;
}

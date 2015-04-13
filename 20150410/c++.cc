/*************************************************************************
    > File Name: c++.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Thu 09 Apr 2015 07:43:31 PM PDT
 ************************************************************************/

#include<iostream>
using namespace std;

class human
{
	public:
		human(const string &name):human_name(name)
		{
			human_num ++;
		}
	static int human_num;
	~human()
	{
		human_num--;
		cout << this->human_name <<"~~";
		print();
	}
	void print()
	{
		cout << this ->human_name << "  human num is :" << human_num << endl;
	}
	protected:
	private:
		string human_name;
};
int human::human_num = 0;
human f1(human x)
{
	human s = x;
	cout << "f1" << " ";
	s.print();
	x.print();
	return x;
	/*
	cout << "f1" <<" ";
	x.print();
	return x;
	*/
}
int main(int argc, char *argv[])
{
	human h1("h1");
	h1.print();
	human h2 = f1(h1);
	h2.print();

	return 0;
}


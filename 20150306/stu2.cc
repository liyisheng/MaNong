/*************************************************************************
    > File Name: stu2.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Sun 08 Mar 2015 03:56:06 PM CST
 ************************************************************************/

#include"stu2.h"
#include<iostream>
#include<string>
using namespace std;

Student::Student(int id, std::string &name, int age)
	:id_(id), name_(name), age_(age)
{

}

void Student::print()
{
	cout << "name :" << name_ << endl
		 << "id :" << id_ << endl
		 << "age:" << age_ << endl;
}

void Student::print() const 
{
	cout << "name :" << name_ << endl
		 << "id :" << id_ << endl
		 << "age:" << age_ << endl;
}

Student &Student::setId(int id)
{
	id_ = id;
	return *this;
}
Student &Student::setName(string &name)
{
	name_ = name;
	return *this;
}
Student &Student::setAge(int age)
{
	age_ = age;
	return *this;
}
#if 0
int main(int argc, char *argv[])
{
	string name = "lisi";
	Student s;
	s.setId(1);
	s.setName(name);
	s.setAge(29);

	s.print();

	const Student *ps = &s;
	ps -> print();
	return 0;
}
#endif

int main(void)
{
	string name = "lisi";
	{
		Student s;
		s.setId(1).setName(name).setAge(29);
		s.print();
	}
	return 0;
}

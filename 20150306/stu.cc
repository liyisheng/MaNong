/*************************************************************************
    > File Name: stu.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Sun 08 Mar 2015 03:25:35 PM CST
 ************************************************************************/

#include"stu.h"
#include<string>
#include<iostream>

using namespace std;

Student::Student(int id, std::string name, int age)
	:id_(id), name_(name), age_(age)
{
	                                                                                                                                 
}

void Student::print()
{
	std::cout << "name :" << name_ << std::endl
			  << "id :" << id_ << std::endl
			  << "age :" << age_ << std::endl;
}

void Student::print() const
{
	std::cout << "name :" << name_ << std::endl
			  << "id :" << id_ << std::endl
			  << "age :" << age_ << std::endl;
}

void Student::setId(int id)
{
	id_ = id;
}

void Student::setName(std::string name)
{
	name_ =  name;
}

void Student::setAge(int age)
{
	age_ = age;
}

int main(int argc, char *argv[])
{
	std::string name = "lisi";
	Student s1(1, name, 29);
	Student s;

	s1.print();
	return 0;
}

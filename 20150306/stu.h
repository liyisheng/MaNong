/*************************************************************************
    > File Name: stu.h
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Sun 08 Mar 2015 03:26:39 PM CST
 ************************************************************************/

#ifndef _STU_H
#define _STU_H

#include<string>

class Student
{
	public:
		Student(int id, std::string name, int age);
		Student(){}
		void print();
		void print() const;
		void setId(int id);
		void setName(std::string name);
		void setAge(int age);
	private:
		int id_;
		std::string name_;
		int age_;
};

#endif

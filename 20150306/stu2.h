/*************************************************************************
    > File Name: stu2.h
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Sun 08 Mar 2015 03:44:38 PM CST
 ************************************************************************/

#ifndef _STU2_H
#define _STU2_H

#include<string>
#include<iostream>
using namespace std;
class Student
{
	public:
		Student(int id, string &name, int age);
		Student()
		{
			cout << "student construct" << endl;
		}

		~Student()
		{
			cout << "student destroy" << endl;
		}

		void print();
		void print() const;

		Student &setId(int id);
		Student &setName(string &name);
		Student &setAge(int age);
	private:
		int id_;
		string name_;
		int age_;
};

#endif

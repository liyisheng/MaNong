/*************************************************************************
    > File Name: student.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Sun 08 Mar 2015 04:04:39 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

struct Student
{
	int id_;
	string name_;
	int age_;

	string m_nickname;

	void print()
	{
		cout << "number : " << id_
			 << "name : " << name_
			 << "age : " << age_ << endl;
	}
};


class Person
{
	private:
		int id_;
		string name_;
		int age_;
	public:
		void print()
		{
			cout << "number : " << id_
				<< "name : " << name_
				<< "age : " << age_ << endl;
		}
		void setId(int id)
		{
			id_ = id;
		}
		void setName(string name)
		{
			name_ = name;
		}
		void setAge(int age)
		{
			age_ = age;
		}
};

int main(int argc, char *argv[])
{
	Person person1;
	person1.setId(2);
	person1.setName("zhangsan");
	person1.setAge(23);

	person1.print();


	Student s1;
	s1.id_ = 1;
	s1.name_ = "lwh";
	s1.age_ = 28;

	Student *ps1 = &s1;
	ps1->print();
	return 0;
}

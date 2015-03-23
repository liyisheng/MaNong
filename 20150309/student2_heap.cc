#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

class Student
{
	public:
		int iId;
		char szName[10];
	public:
		Student()
		{
			std::cout << "Student 构造函数被调用" << std::endl;
		}

		void destroy()
		{
			this ->~Student();
		}

	private:
		~Student()
		{
			std::cout << "Student 析构函数被调用" << std::endl;
		}

};

class Teacher
{

};

int main(void)
{
	Student *pstu = new Student;
	pstu->iId = 101;
	strcpy(pstu->szName, "Tony");


	pstu->destroy();
	//Student stu;


	return 0;
}

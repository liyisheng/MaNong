/*************************************************************************
  > File Name: test.cc
  > Author: liyisheng
  > Mail: liyishengchn@gmail.com 
  > Created Time: Fri 20 Mar 2015 10:43:46 PM CST
 ************************************************************************/


//11-11 使用虚析构函数解决内存泄漏问题
#include <iostream>
using namespace std;

class Base					//基类定义
{

	private:
		char* data;				//字符指针

	public:
		Base()					//无参构造函数
		{

			data = new char[64];	//动态内存申请
			cout << "Base类构造函数被调用" << endl;
		};

		virtual ~Base()			//虚析构函数
		{

			delete [] data;		//data指向的内存被释放
			cout << "Base类析构函数被调用" << endl;
		};
};

class Child : public Base		//Child类由基类Base派生而来
{

	private:
		char* m_data;				//增添的字符指针成员

	public:
		Child():Base()				//构造函数，初始化表中执行基类的构造函数
	{

		m_data = new char[64];	//动态申请内存，并将首地址赋给m_data
		cout << "Child类构造函数被调用" << endl;
	};

		~Child()					//析构函数，继承虚拟virtual
		{

			delete [] m_data;		//内存资源释放
			cout << "Child类析构函数被调用" << endl;
		};
};

class GrandChild:public Child	//GrandChild类由Child类派生而来
{

	private:
		char* mm_data;				//在Child类基础上增加的字符指针成员mm_data

	public:
		GrandChild():Child()		//构造函数
	{

		mm_data = new char[64];	//动态内存申请
		cout << "GrandChild类构造函数被调用" << endl;
	};

		~GrandChild()				//虚析构函数，virtual从继承结构中得来
		{

			delete [] mm_data;		//内存释放
			cout << "GrandChild类析构函数被调用" << endl;
		};
};

int main()
{

//	Base *pB = new Child;			//动态申请了一块Child大小的内存，赋给Base基类指针
//	delete pB;						//Child类的析构函数执行，释放内存，不会泄露

	cout << endl;

//	Child* pC = new GrandChild;		//动态申请了一块GrandChild大小的内存，赋给Child类指针
//	delete pC;						//GrandChild类的析构函数执行，释放内存，不会泄露
//	cout << endl;

	GrandChild *pG = (GrandChild *)new Base;
	delete pG;	//如果去掉基类析构函数前的virtual, 执行到delete [] mm_data时会报内存错误, 因为mm_data根本就没有new

	return 0;
}



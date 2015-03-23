/*************************************************************************
    > File Name: map_erase.cpp
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Fri 13 Mar 2015 11:07:38 PM CST
 ************************************************************************/

#include <iostream>
#include <map>
#include <string>
using namespace std;

typedef map<int,string> CM;								//typedef简化定义
typedef CM::value_type CMV;								//CMV实际上等价于pair<int,string>
typedef CM::iterator CMI;
typedef multimap<int,string> MCM;
typedef MCM::iterator MCMI;

void disp(CM &x)										//定义CM类型元素遍历输出函数disp
{

	for (CMI it = x.begin(); it != x.end(); it++)
	{

		cout<<(*it).first<<"  "<<(*it).second<<endl;
	}
}

void disp(MCM& x)										//重载MCM类型元素遍历输出函数
{

	for (MCMI it=x.begin();it!=x.end();it++)
	{

		cout<<(*it).first<<"  "<<(*it).second<<endl;
	}
}

int main()
{

	CMV sz[3] = {
		CMV(1,"A"),CMV(2,"B"),CMV(1,"C")};		//相当于定义了一个pair<int,string>数组
	//1. map
	CM obM(sz, sz+3);									//创建map<int,string>对象
	disp(obM);											//元素遍历输出

	CM::size_type num1 = obM.erase(1);
	cout << "删除所有关键字为1的元素后" << endl;
	disp(obM);
	cout << "共删除了" << num1 << "个元素" << endl << endl << endl;

	//2. multimap
	MCM obDM(sz, sz+3);									//创建multimap<int,string>对象
	disp(obDM);											//元素遍历输出		

	MCM::size_type num2 = obDM.erase(1);
	cout << "删除所有关键字为1的元素后" << endl;
	disp(obDM);
	cout << "共删除了" << num2 << "个元素" << endl;

	//3. 
//	getchar();
	return 0;
}

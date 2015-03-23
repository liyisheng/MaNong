/*************************************************************************
    > File Name: map_find.cpp
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Sat 14 Mar 2015 09:03:21 AM CST
 ************************************************************************/

//容器元素的遍历、查找与排序等综合应用
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <map>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;

#pragma warning(disable:4996)

class CMyString;
ostream &operator<<(ostream &os, const CMyString &s);
CMyString operator+(const CMyString &s1, const CMyString &s2);

class CMyString
{

	private:
		char *m_pData;

	public:
		CMyString()
		{
			m_pData = new char[1];
			m_pData[0] = '\0';
		}

		CMyString(const char *pBuf)
		{
			if (pBuf == NULL)
			{
				m_pData = new char[1];
				m_pData[0] = '\0';
			}
			else
			{
				m_pData = new char[strlen(pBuf) + 1];
				strcpy(m_pData, pBuf);
			}
		}

		CMyString(const CMyString &s)
		{
			m_pData = new char[strlen(s.m_pData) + 1];
			strcpy(m_pData, s.m_pData);
		}

		//map容器要求CMyString类的个比较运算符定义为const类型, 如果去掉const将报如下错误: 
		//error C2678: 二进制“<”: 没有找到接受“const CMyString”类型的左操作数的运算符(或没有可接受的转换)
		bool operator==(const CMyString &s) const
		{
			return (strcmp(this->m_pData, s.m_pData) == 0);
		}
		bool operator==(const char *s) const
		{
			return (strcmp(this->m_pData, s) == 0);
		}

		//bool operator!=(const CMyString &s) const
		//{

		//	return (strcmp(this->m_pData, s.m_pData) != 0);
		//}

		bool operator<(const CMyString &s) const
		{
			return (strcmp(this->m_pData, s.m_pData) < 0);
		}

		//bool operator>(const CMyString &s) const
		//{

		//	return (strcmp(this->m_pData, s.m_pData) > 0);
		//}

		//bool operator<=(const CMyString &s) const
		//{

		//	return (strcmp(this->m_pData, s.m_pData) <= 0);
		//}

		//bool operator>=(const CMyString &s) const
		//{

		//	return (strcmp(this->m_pData, s.m_pData) >= 0);
		//}

		//char * operator()() const
		//{

		//	return m_pData;
		//}

		CMyString &operator=(const CMyString &s)
		{

			if (this != &s)
			{
				delete m_pData;
				m_pData = new char[strlen(s.m_pData) + 1];
				strcpy(m_pData, s.m_pData);
			}
			return (*this);
		}

		char &operator[](const unsigned int &i)
		{
			return m_pData[i];
		}

		operator char*()
		{
			return m_pData;
		}

		friend CMyString operator+(const CMyString &s1, const CMyString &s2);
		friend ostream &operator<<(ostream &os, const CMyString &s);

		int GetLength()
		{
			return strlen(m_pData) + 1;
		}

		char *GetBuffer()
		{
			return m_pData;
		}

		~CMyString()
		{
			delete m_pData;
			m_pData = NULL;
		}
};

CMyString operator+(const CMyString &s1, const CMyString &s2)
{
	char *pTemp = new char[strlen(s1.m_pData) + strlen(s2.m_pData) + 1];
	strcpy(pTemp, s1.m_pData);
	strcat(pTemp, s2.m_pData);
	return CMyString(pTemp);
}

ostream &operator<<(ostream &os, const CMyString &s)
{
	os << s.m_pData;
	return os;
}

void PrintCString(CMyString &s)
{
	cout << s << "  ";
}

void PrintPair(pair<CMyString, string> ob)
{

	cout << ob.first << "  " << ob.second << endl;
}

void TestVector()
{
	//1. vector和deque支持随机访问, 将本函数中的vector类型替换成deque类型后，结果一样
	//测试自定义数据类型CMyString做为vector元素的用法
	vector<CMyString> obV;
	obV.push_back("A");
	obV.push_back("B");
	obV.push_back("C");
	obV.push_back(CMyString("A"));
	obV.push_back(CMyString("B"));
	obV.push_back(CMyString("C"));

	//调用for_each()泛型算法来遍历vector容器的每个元素
	for_each(obV.begin(), obV.end(), PrintCString);
	cout << endl;

	//调用sort泛型算法对vector容器元素进行排序, vector容器本身并没有提供sort算法
	sort(obV.begin(), obV.end());	//泛型算法sort()要求CMyString类对比较运算符<进行了重载
	for_each(obV.begin(), obV.end(), PrintCString);
	cout << endl;

	//使用find泛型算法找到第一元素B并删除之
	vector<CMyString>::iterator itV = find(obV.begin(), obV.end(), CMyString("B"));
	if (itV != obV.end())
	{

		obV.erase(itV);
	}
	for_each(obV.begin(), obV.end(), PrintCString);
	cout << endl;

	//使用find泛型算法找到第一元素C并删除其后的所有元素
	itV = find(obV.begin(), obV.end(), CMyString("C"));
	if (itV != obV.end())
	{

		obV.erase(itV, obV.end());
	}
	for_each(obV.begin(), obV.end(), PrintCString);
	cout << endl;
	cout << endl;
}

void TestList()
{

	//2. list
	list<CMyString> obL;
	obL.push_back("X");
	obL.push_back("Y");
	obL.push_back("Z");
	obL.push_back("X");
	obL.push_back("Y");
	obL.push_back("Z");

	//排序前遍历list
	for_each(obL.begin(), obL.end(), PrintCString);
	cout << endl;

	//使用list自身的sort()算法对obL排序
	obL.sort();
	for_each(obL.begin(), obL.end(), PrintCString);
	//sort(obL.begin(), obL.end());		//不能使用泛型算法sort对list容器容器排序, 因为list不支持随机访问
	cout << endl;

	//find and erase Y
	list<CMyString>::iterator itL = find(obL.begin(), obL.end(), "Y");
	if (itL != obL.end())
	{

		obL.erase(itL);
	}
	for_each(obL.begin(), obL.end(), PrintCString);
	cout << endl;

	//find and erase Z Z
	itL = find(obL.begin(), obL.end(), "Z");
	if (itL != obL.end())
	{

		obL.erase(itL, obL.end());
	}
	for_each(obL.begin(), obL.end(), PrintCString);
	cout << endl;
	cout << endl;
}

void TestMap()
{

	//3. map要求CMyString类的== 和< 比较运算符定义为const类型
	pair<CMyString, string> sz[] = {
		pair<CMyString, string>("北京", "华北"), pair<CMyString, string>("深圳", "华南")};
	map<CMyString, string> obM(sz, sz+2);
	obM.insert(pair<CMyString, string>("杭州", "华东"));
	obM["武汉"] = "华中";
	obM["厦门"] = "华南";
	obM["上海"] = "华南";	//上海不是华南, 错了
	obM["上海"] = "华东";	//更正上海为华东
	for_each(obM.begin(), obM.end(), PrintPair);
	cout << endl;

	//对map容器不能使用find泛型算法, 要使用map自身提供的find算法
	//find(obM.begin(), obM.end(), pair<CMyString, string>("厦门", "华南"));
	map<CMyString, string>::iterator itM = obM.find("厦门");
	if (itM != obM.end())
	{

		obM.erase(itM);
	}
	for_each(obM.begin(), obM.end(), PrintPair);
}

//测试自定义数据类型CMyString做为vector, list, map的元素的用法
int main()
{

	//1. vector和deque支持随机访问
	TestVector();

	//2. list
	TestList();

	//3. Map
	TestMap();

	//4. return
	system("pause");
	return 0;
}

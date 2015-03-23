/*************************************************************************
    > File Name: map_insert.cpp
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Fri 13 Mar 2015 10:40:30 PM CST
 ************************************************************************/

#include<iostream>
#include<map>

using namespace std;

int main(int argc, char *argv[])
{
	pair<int,string> sz[2] = {pair<int,string>(1,"A"), pair<int,string>(2,"B")};
	pair<int,string> t(3,"X");

	map<int,string> obm(sz, sz+2);
	map<int,string>::iterator itm = obm.begin();

	pair<map<int,string>::iterator, bool> res = obm.insert(t);

	if(res.second)
		cout<< "插入成功" <<endl;
	else
		cout << "插入失败" <<endl;
	return 0;
}

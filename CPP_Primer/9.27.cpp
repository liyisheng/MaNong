/*************************************************************************
    > File Name: 9.27.cpp
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Sun 15 Mar 2015 04:11:46 PM CST
 ************************************************************************/

#include<iostream>
#include<list>
#include<deque>
#include<string>
#include<algorithm>
using namespace std;

int main(int argc, char *argv[])
{
/*	list<string> slist;
	string str;
	while(cin >> str)
		slist.push_back(str);
	

	list<string>::iterator iwant = find(slist.begin(), slist.end(), "fuck");
	slist.erase(iwant);
	for(list<string>::iterator it = slist.begin(); it != slist.end(); ++it)
		cout << *it << endl;
*/
//deque
	deque<string> sdeque;	
	string str2;
	while(cin >> str2)
		sdeque.push_back(str2);
	deque<string>::iterator iwant2 = find(sdeque.begin(), sdeque.end(), "fuck");
	sdeque.erase(iwant2);

	for(int i = 0; i != sdeque.size(); ++i)
		cout << sdeque[i] << endl;
	return 0;
}

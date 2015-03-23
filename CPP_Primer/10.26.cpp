/*************************************************************************
    > File Name: 10.26.cpp
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Mon 16 Mar 2015 03:23:30 PM CST
 ************************************************************************/

#include<iostream>
#include<map>
#include<string>
using namespace std;


int main(int argc, char *argv[])
{
	multimap<string, string> authors;
	string author, work, searchItem;

	do{
		cout << "Enter author name: " << endl;
		cin >> author;
		if(!cin)
			break;
		cout << "Enter author's works'" << endl;
		while(cin >> work)
			authors.insert(make_pair(author, work));
		cin.clear();
	}while(cin);
	cin.clear();

	cout << "Who is the author that you want erase:" << endl;
	cin >> searchItem;
	multimap<string, string>::iterator iter = authors.find(searchItem);
	if(iter != authors.end())
	//	authors.erase(searchItem);
		authors.erase(iter);
	else
		cout << "Can not find this author" << endl;
	cout << "author\t\twork:" <<endl;
	for(iter = authors.begin(); iter != authors.end(); ++iter)
		cout << iter->first << "\t\t" << iter->second << endl;
	return 0;
}

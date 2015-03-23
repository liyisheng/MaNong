/*************************************************************************
    > File Name: 8.7.cpp
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Wed 18 Mar 2015 01:10:15 AM CST
 ************************************************************************/


#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

int main(int argc, char *argv[])
{
	const char* a[] = { "10.1.cpp", "11.11.cpp", "10.1.cpp"};
	vector<string> svec(a, a + 3);
	vector<string>::iterator it = svec.begin();
	string s;
	while(it != svec.end())
	{
		ifstream input(it->c_str());
		if(!input)
		{
	//		cout << " break" << endl;
		//	break;
			cout << "error" << endl;
		}
		if(input)
			cout << "process(s)" << endl;
		++it;
	}
	return 0;
}

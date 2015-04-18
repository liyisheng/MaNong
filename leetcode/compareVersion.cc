/*************************************************************************
    > File Name: compareVersion.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Tue 14 Apr 2015 05:29:00 AM PDT
 ************************************************************************/

#include<iostream>
#include<stdlib.h>
using namespace std;

int compareVersion(string version1, string version2)
{
	if(version1 == version2)
		return 0;
	size_t f1 = 0;
	size_t f2 = 0;
	size_t found1 = version1.find('.');
	size_t found2 = version2.find('.');
	while(found1 != string::npos && found2 != string::npos)
	{
		if(atoi(version1.substr(f1, found1 - f1).c_str()) < atoi(version2.substr(f2, found2 - f2).c_str()) )
			return -1;
		else if(atoi(version1.substr(f1, found1 - f1).c_str()) > atoi(version2.substr(f2, found2 - f2).c_str()) )
			return 1;
		f1 = found1 + 1;
		f2 = found2 + 1;
		found1 = version1.find('.', found1 + 1);
		found2 = version2.find('.', found2 + 1);
	}
	if(found1 == string::npos && found2 != string::npos)
	{
		if(atoi(version1.substr(f1).c_str()) < atoi(version2.substr(f2, found2 - f2).c_str()) )
			return -1;
		else if(atoi(version1.substr(f1).c_str()) > atoi(version2.substr(f2, found2 - f2).c_str()) )
			return 1;
		else
		{
			do{
				f2 = found2 + 1;
			}while((found2 = version2.find('.', found2 + 1) ) != string::npos);
			if(atoi(version2.substr(f2).c_str()) != 0)
				return -1;
			else
				return 0;
		}
	}else if(found1 != string::npos && found2 == string::npos)
	{
		if(atoi(version1.substr(f1, found1 - f1).c_str()) < atoi(version2.substr(f2).c_str()) )
			return -1;
		else if(atoi(version1.substr(f1, found1 - f1).c_str()) > atoi(version2.substr(f2).c_str()) )
			return 1;
		else
		{
			do{
				f1 = found1 + 1;	
			}while((found1 = version1.find('.', found1 + 1)) != string::npos);
			if(atoi(version1.substr(f1).c_str()) != 0)
				return 1;
			else 
				return 0;
		}
	}else if(found1 == string::npos && found2 == string ::npos)
	{
		if(atoi(version1.substr(f1).c_str()) < atoi(version2.substr(f2).c_str()) )
			return -1;
		else if(atoi(version1.substr(f1).c_str()) > atoi(version2.substr(f2).c_str()) )
			return 1;
		else
			return  0;
	}

}

int main(int argc, char *argv[])
{
	cout << compareVersion("1.0", "1");
	return 0;
}

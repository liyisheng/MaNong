/*************************************************************************
    > File Name: 3.5.cpp
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Fri 13 Mar 2015 11:20:59 AM CST
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

int main(int argc, char *argv[])
{
	std::string line;
	std::string word;
	while(getline(cin, line))
	//while(std::cin >> word)
	{
		//std::cout << word << std::endl;	
		std::cout << line << std::endl;	

	}
	return 0;
}

/*************************************************************************
    > File Name: io3.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Sat 07 Mar 2015 11:31:09 AM CST
 ************************************************************************/

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

int test0(void)
{
	ifstream ifs("io1.cc");
	if(!ifs.good())
	{
		cout << "open file error" << endl;
		return -1;
	}

	vector<string> vec_str;
	string line;

	while(getline(ifs, line))
	{
		cout << line << endl;
		vec_str.push_back(line);
	}

	vector<string>::iterator sit = vec_str.begin();
	for(; sit != vec_str.end(); sit++)
	{
		cout << *sit << endl;
	}

	ifs.close();
}

int main(int argc, char *argv[])
{
//	test0();
	std::ifstream ifs("io1.cc");
	if(!ifs.good())
	{
		std::cout << "open file error!" << std::endl;
		return -1;
	}

	std::ofstream ofs("test.txt");
	std::string line;
	while(getline(ifs,line))
	{
//		std::cout << line << std::endl;
		ofs << line << std::endl;
	}
//	ifs.close();
	return 0;
}

/*************************************************************************
    > File Name: word_map.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Mon 16 Mar 2015 01:38:04 AM CST
 ************************************************************************/

#include<iostream>
#include<map>
#include<fstream>
#include<sstream>
#include<stdexcept>
using namespace std;

ifstream & open_file(ifstream &in, const string &file);

int main(int argc, char *argv[])
{
	map<string, string> trans_map;
	string key, value;
	if(argc != 3)
	{
		throw runtime_error("wrong number of arguments");
	}

	ifstream map_file;
	if(!open_file(map_file, argv[1]))
		throw runtime_error("no transformation file");

	while(map_file >> key >> value)
		trans_map.insert(make_pair(key,value));

	ifstream input;
	if(!open_file(input, argv[2]))
		throw runtime_error("no input file");

	string line;
	while(getline(input, line))
	{
		istringstream stream(line);
		string word;	
		bool firstword = true;
		while(stream >> word)
		{
			map<string, string>::const_iterator map_it = trans_map.find(word);
			if(map_it != trans_map.end())
				word = map_it ->second;
			if(firstword)
				firstword = false;
			else
				cout << " ";
			cout << word;
		}
		cout << endl;
	}
	return 0;
}

ifstream & open_file(ifstream &in, const string &file)
{
	in.close();
	in.clear();
	in.open(file.c_str());
	return in;
}

/*************************************************************************
  > File Name: 10.3.9.cpp
  > Author: liyisheng
  > Mail: liyishengchn@gmail.com 
  > Created Time: 2015年04月26日 星期日 15时29分18秒
 ************************************************************************/

#include<iostream>
#include<fstream>
#include<sstream>
#include<map>
#include<vector>
using namespace std;
ifstream & openfile(ifstream &in, const string &file)
{
	in.close();
	in.clear();
	in.open(file.c_str());
	return in;
}

int main(int argc, char *argv[])
{

	map<string, string> word_trans;
	string key, value;

	ifstream map_file;
	if(!openfile(map_file, "10.3.9.txt"))
		cerr << "no transformation file" << endl;
	while(map_file >> key >> value)
		word_trans.insert(make_pair(key, value));

	string line;
	while(getline(cin,line))
	{
		istringstream stream(line);
		string word;
		bool firstword = true;
		while(stream >> word)
		{
			map<string, string>::const_iterator map_it = word_trans.find(word);
			if(map_it != word_trans.end())
				word = map_it->second;
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



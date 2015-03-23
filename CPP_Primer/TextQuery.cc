/*************************************************************************
    > File Name: TesxQuery.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Mon 16 Mar 2015 03:58:03 PM CST
 ************************************************************************/
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<set>
#include<vector>
#include<map>
#include<cstdlib>
#include<stdexcept>
using namespace std;
class TextQuery
{
	public:
		typedef vector<string>::size_type line_no;
		void read_file(ifstream &is) // 读文件
		{
			store_file(is);
			build_map();
		}
		set<line_no> run_query(const string&) const; //返回单词的行号set
		string text_line(line_no) const; //返回行号对应的文本行
	private:	
		void store_file(ifstream&); //读文件，按行存在 line_of_text容器里
		void build_map(); // 将每一行分解为各个单词， 创建map容器对象， 记录每个单词出现的行号
		vector<string> line_of_text;  //存储这个输入文件的副本
		map< string, set<line_no> > word_map; //将每个单词 与一个set容器对象关联起来， set中记录单词的行数
};

void print_results(const set<TextQuery::line_no> &locs, const string &s, const TextQuery &file);
ifstream & open_file(ifstream &in, const string &file);
string make_plural(set<TextQuery::line_no>::size_type size, const string &word, const string &ending);

int main(int argc, char *argv[])
{
	ifstream infile;
	if(argc < 2 || !open_file(infile, argv[1]))
	{
		cerr << "No input file!" << endl;
		return EXIT_FAILURE;
	}
	TextQuery tq;
	tq.read_file(infile);
	while(true)
	{
		cout << "enter word to look for, or q to quit:";
		string s;
		cin >> s;
		if(!cin || s == "q")
			break;
		set<TextQuery::line_no> locs = tq.run_query(s);
		print_results(locs, s, tq);
	}
	return 0;
}

void print_results(const set<TextQuery::line_no> &locs, const string &s, const TextQuery &file)
{
	typedef set<TextQuery::line_no> line_nums;	
	line_nums::size_type size = locs.size();
	cout << "\n" << s << "occurs" << size << " " << make_plural(size, "time", "s") << endl;
	line_nums::const_iterator it = locs.begin();
	for(; it != locs.end(); ++it)
		cout << "\t(line" << (*it)+ 1 << ")" << file.text_line(*it) << endl;
}


void TextQuery::store_file(ifstream &is)
{
	string textline;
	while(getline(is, textline))
	{
		line_of_text.push_back(textline);
	}
}

void TextQuery::build_map()
{
	for(line_no line_num = 0; line_num != line_of_text.size(); ++line_num)	
	{
		istringstream line(line_of_text[line_num]);
		string word;
		while(line >> word)
			word_map[word].insert(line_num);
	}
}

set<TextQuery::line_no> TextQuery::run_query(const string &queryword) const
{
	map< string, set<line_no> >::const_iterator loc = word_map.find(queryword);
	if(loc == word_map.end())
		return set<line_no>();
	else
		return loc->second;
}

string TextQuery::text_line(line_no line) const
{
	if(line < line_of_text.size())
		return line_of_text[line];
	throw out_of_range("line number out of range");
}

ifstream & open_file(ifstream &in, const string &file)
{
	in.close();
	in.clear();
	in.open(file.c_str());
	return in;
}

string make_plural(set<TextQuery::line_no>::size_type size, const string &word, const string &ending)
{
	return (size == 1) ? word : word + ending;
}

/*************************************************************************
    > File Name: TextQuery.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Mon 16 Mar 2015 03:58:03 PM CST
 ************************************************************************/
#include"TextQuery.h"
#include<stdexcept>
#include<cctype>
using namespace std;
/*
void 
TextQuery::store_file(ifstream &is)
{
	string textline;
	while(getline(is, textline))
	{
		line_of_text.push_back(textline);
	}
}
*/

void
TextQuery::store_file(ifstream &is)
{
	char ws[] = {'\t', '\r', '\v', '\f', '\n'};
	char eos[] = {'?', '.', '!'};
	set<char> whiteSpace(ws, ws + 5);
	set<char> endOfSentence(eos, eos + 3);	
	string sentence;
	char ch;
	while(is.get(ch))
	{
		if(!whiteSpace.count(ch))
			sentence += ch;
		if(endOfSentence.count(ch))
		{
			line_of_text.push_back(sentence);
			sentence.assign("");
		}
	}
}
void 
TextQuery::build_map()
{
	for(line_no line_num = 0; line_num != line_of_text.size(); ++line_num)	
	{
		istringstream line(line_of_text[line_num]);
		string word;
		while(line >> word)
		{
			if(ispunct(*(word.end() - 1)))
				word.erase(word.end() - 1);
			word_map[word].insert(line_num);
		}
	}
}

set<TextQuery::line_no> 
TextQuery::run_query(const string &queryword) const
{
	map< string, set<line_no> >::const_iterator loc = word_map.find(queryword);
	if(loc == word_map.end())
		return set<line_no>();
	else
		return loc->second;
}

string 
TextQuery::text_line(line_no line) const
{
	if(line < line_of_text.size())
		return line_of_text[line];
	throw out_of_range("line number out of range");
}



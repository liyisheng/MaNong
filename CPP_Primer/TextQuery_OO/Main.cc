/*************************************************************************
    > File Name: Main.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Fri 20 Mar 2015 09:41:04 AM CST
 ************************************************************************/

#include<iostream>
#include<string>
#include<cstdlib>
#include<stdexcept>
#include"Query.h"
#include"TextQuery.h"

using namespace std;
void print_results(const set<TextQuery::line_no> &locs, const string &s, const TextQuery &file);
void print_results(const set<TextQuery::line_no> &locs, const Query &q, const TextQuery &file);
ifstream& open_file(ifstream &in, const string &file);
string make_plural(set<TextQuery::line_no>::size_type size, const string &word, const string &ending);

int main(int argc, char *argv[])
{
	ifstream infile;
	if(argc < 2 || !open_file(infile, argv[1]))
	{
		cerr << "No input file!" << endl;
		return EXIT_FAILURE;
	}
	/*
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
	*/

	TextQuery tq;
	tq.read_file(infile);

//	Query q = Query("fiery") & Query("bird") | Query("wind");
	Query q = Query("fiery") & Query("bird");
//	Query q = Query("fiery");
	set<TextQuery::line_no> locs = q.eval(tq);
	print_results(locs, q, tq);
	return 0;
}

string 
make_plural(set<TextQuery::line_no>::size_type size, const string &word, const string &ending)
{
	return (size == 1) ? word : word + ending;
}

ifstream& 
open_file(ifstream &in, const string &file)
{
	in.close();
	in.clear();
	in.open(file.c_str());
	return in;
}

void 
print_results(const set<TextQuery::line_no> &locs, const string &s, const TextQuery &file)
{
	typedef set<TextQuery::line_no> line_nums;	
	line_nums::size_type size = locs.size();
	cout << "\n" << s << "occurs" << size << " " << make_plural(size, "time", "s") << endl;
	line_nums::const_iterator it = locs.begin();
	for(; it != locs.end(); ++it)
		cout << "\t(line" << (*it)+ 1 << ")" << file.text_line(*it) << endl;
}

void 
print_results(const set<TextQuery::line_no> &locs, const Query &q, const TextQuery &file)
{
	typedef set<TextQuery::line_no> line_nums;	
	line_nums::size_type size = locs.size();
	cout << "Executed Query for :";
	q.display(cout);
	cout << endl << "match occurs  " << size << " " << make_plural(size, "time", "s") << endl;
	line_nums::const_iterator it = locs.begin();
	for(; it != locs.end(); ++it)
		cout << "\t(line" << (*it)+ 1 << ")" << file.text_line(*it) << endl;
}


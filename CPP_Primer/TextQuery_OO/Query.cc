/*************************************************************************
    > File Name: Query.cpp
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Thu 19 Mar 2015 11:30:16 PM CST
 ************************************************************************/

#include<iostream>
#include"Query.h"
#include<algorithm>

using namespace std;

Query::Query(const string& s)
{	
q = (new WordQuery(s));
use = (new size_t(1));
}


set<TextQuery::line_no>
OrQuery::eval(const TextQuery& file) const
{
	set<line_no> right = rhs.eval(file);
	set<line_no> ret_lines = lhs.eval(file);

	ret_lines.insert(right.begin(), right.end());

	return ret_lines;
}

set<TextQuery::line_no>
AndQuery::eval(const TextQuery& file) const
{
	set<line_no> left = lhs.eval(file),
		right = rhs.eval(file);
	set<line_no> ret_lines;
	
	set_intersection(left.begin(), left.end(), right.begin(), right.end(), 
			inserter(ret_lines, ret_lines.begin()));
	return ret_lines;
}


set<TextQuery::line_no>
NotQuery::eval(const TextQuery& file) const
{
	set<line_no> has_val = query.eval(file);
	set<line_no> ret_lines;
	for(TextQuery::line_no n = 0; n != file.size(); ++n)
		if(has_val.find(n) == has_val.end())
			ret_lines.insert(n);
}



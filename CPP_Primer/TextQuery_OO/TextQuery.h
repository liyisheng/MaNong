/*************************************************************************
    > File Name: TextQuery.h
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Fri 20 Mar 2015 12:32:30 AM CST
 ************************************************************************/

#ifndef _TEXTQUERY_H
#define _TEXTQUERY_H

#include<vector>
#include<map>
#include<fstream>
#include<sstream>
#include<set>
class TextQuery
{
	public:
		typedef std::vector<std::string>::size_type line_no;
		void read_file(std::ifstream &is) // 读文件
		{
			store_file(is);
			build_map();
		}
		std::set<line_no>
			run_query(const std::string&) const; //返回单词的行号set
		std::string
			text_line(line_no) const; //返回行号对应的文本行
		line_no size() const
		{
			return line_of_text.size();	
		} 
	private:	
		void store_file(std::ifstream&); //读文件，按行存在 line_of_text容器里
		void build_map(); // 将每一行分解为各个单词， 创建map容器对象， 记录每个单词出现的行号
		std::vector<std::string> line_of_text;  //存储这个输入文件的副本
		std::map< std::string, std::set<line_no> > word_map; //将每个单词 与一个set容器对象关联起来， set中记录单词的行数
};

#endif

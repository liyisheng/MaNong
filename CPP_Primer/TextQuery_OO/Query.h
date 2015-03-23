/*************************************************************************
  > File Name: Query.h
  > Author: liyisheng
  > Mail: liyishengchn@gmail.com 
  > Created Time: Thu 19 Mar 2015 11:05:08 PM CST
 ************************************************************************/
#ifndef _QUERY_H
#define _QUERY_H
#include"TextQuery.h"
#include<iostream>
class Query_base
{
	friend class Query;
protected:
	typedef TextQuery::line_no line_no;
	virtual ~Query_base(){
	}
private:
	virtual std::set<line_no> 
		eval(const TextQuery&) const = 0;
	virtual std::ostream& 
		display(std::ostream& = std::cout) const = 0;
};
class Query
{
	friend Query operator~(const Query &);
	friend Query operator|(const Query &, const Query &);
	friend Query operator&(const Query &, const Query &);
public:
	Query(const std::string &);
	Query(const Query &c) : q(c.q),use(c.use)
	{
		++*use;
	}
	Query& operator=(const Query&);
	~Query()
	{
		decr_use();
	}
	std::set<TextQuery::line_no>
		eval(const TextQuery &t) const
		{
			return q ->eval(t);
		}
	std::ostream &display(std::ostream &os) const
	{
		return q ->display(os);
	}
private:
	Query(Query_base *query) : q(query),use(new std::size_t(1)){}
	Query_base *q;
	std::size_t *use;
	void decr_use()
	{
		if(--*use == 0)
		{
			delete q;
			delete use;
		}
	}
};
inline std::ostream& operator<<(std::ostream &os, const Query &q)
{
	return q.display(os);
}
class WordQuery : public Query_base
{
	friend class Query;
	WordQuery(const std::string &s) : query_word(s){
	}
	std::set<line_no> eval(const TextQuery &t) const
	{
		return t.run_query(query_word);
	}
	std::ostream& display(std::ostream &os) const
	{
		return os << query_word;
	}
	std::string query_word;
};
class NotQuery : public Query_base
{
	friend Query operator ~(const Query &);
	NotQuery(Query q) : query(q){
	}
	std::set<line_no> eval(const TextQuery&) const;
	std::ostream& display(std::ostream &os) const
	{
		return os << "~(" << query << ")";
	}
	const Query query;
};
class BinaryQuery : public Query_base
{
	protected:
		BinaryQuery(Query left, Query right, std::string op):
			lhs(left), rhs(right), oper(op) {
			}
		std::ostream& display(std::ostream &os) const
		{
			return os << "(" << lhs << " " << oper << " " << rhs << ")";
		}
		const Query lhs, rhs;
		const std::string oper; //name of the operator
};
class AndQuery : public BinaryQuery
{
	friend Query operator &(const Query&, const Query &);
	AndQuery(Query left, Query right):
		BinaryQuery(left, right, "&"){
		}
	std::set<line_no> 
	eval(const TextQuery&) const;
};
class OrQuery: public BinaryQuery
{
	friend Query operator |(const Query&, const Query &);
	OrQuery(Query left, Query right):
		BinaryQuery(left, right, "|"){
		}
	std::set<line_no> 
	eval(const TextQuery&) const;
};
inline Query operator&(const Query &lhs, const Query &rhs)
{
	return new AndQuery(lhs, rhs);
}
inline Query operator|(const Query &lhs, const Query &rhs)
{
	return new OrQuery(lhs, rhs);
}
inline Query operator~(const Query &oper)
{
	return new NotQuery(oper);  
	//返回Query_base派生类指针，隐式调用Query接受Query_base*构造函数
}
#endif

/*************************************************************************
    > File Name: 15.3.cpp
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Wed 18 Mar 2015 10:38:16 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

class Item_base
{
public:
	Item_base(const string &book = "", double sales_price = 0.0):
		isbn(book), price(sales_price){}
	string book() const
	{
		return isbn;
	}
	virtual double net_price(size_t n) const
	{
		return n * price;
	}
private:
	string isbn;
protected:
	double price;
};

class Bulk_item : public Item_base
{
public:
	double net_price(size_t) const;
private:
	size_t min_qty;
	double discount;
};

double Bulk_item::net_price(size_t cnt) const
{
	if(cnt >= min_qty)
		return cnt * (1 - discount) * price;
	else
		return cnt * price;
}

class Lds_item : public Item_base
{
	public:
		Lds_item(const string &book = "", double sales_price = 0.0,
				size_t qty = 0, double disc_rate = 0.0):
			Item_base(book, sales_price), max_qty(qty), discount(disc_rate){}

		double net_price(size_t cnt) const	
		{
			if(cnt <= max_qty )
				return cnt * (1 - discount) * price;
			else
				return cnt * price - max_qty * discount * price;
		}
	private:
		size_t max_qty;
		double discount;
};

int main(int argc, char *argv[])
{
	return 0;
}

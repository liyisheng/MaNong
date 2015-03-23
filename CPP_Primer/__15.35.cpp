/*************************************************************************
    > File Name: 15.35.cpp
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Thu 19 Mar 2015 03:05:40 PM CST
 ************************************************************************/

#include<iostream>
#include<stdexcept>
#include<set>
using namespace std;


class Item_base
{
	public:
		Item_base(const string &book = "",
				double sales_price = 0.0):
			isbn(book),price(sales_price){}
		string book() const
		{
			return isbn;
		}
		virtual double net_price(size_t n) const
		{
			return n * price;
		}
		virtual Item_base * clone() const
		{
			return new Item_base(*this);
		}
	private:
		string isbn;
	protected:
		double price;
};
//保存折扣率和可实行折扣策略的数量
//派生类将使用这些数据实现定价策略
class Disc_item : public Item_base
{
	public:
		Disc_item(const string &book = "", double sales_price = 0.0,
				size_t qty = 0, double disc_rate = 0.0):
			Item_base(book, sales_price), quantity(qty), discount(disc_rate){}
		double net_price(size_t) const = 0;
	protected:
		size_t quantity; //可实行折扣策略的购买量
		double discount; //折扣率
};
//批量购买折扣类
class Bulk_item : public Disc_item
{
	public:
		Bulk_item(const string &book = "", double sales_price = 0.0,
				size_t qty = 0.0, double disc_rate = 0.0):
			Disc_item(book, sales_price, qty, disc_rate){}
		double net_price(size_t n) const
		{
			if(n >= quantity)
				return n * (1 - discount) * price;
			else
				return n * price;
		}
		virtual Bulk_item* clone() const
		{
			return new Bulk_item(*this);
		}
};

//有限折扣类
class Lds_item : public Disc_item
{
	public:
		Lds_item(const string &book = "", double sales_price = 0.0,
				size_t qty = 0.0, double disc_rate = 0.0):
			Disc_item(book, sales_price, qty, disc_rate){}
		double net_price(size_t n) const
		{
			if(n <= quantity)
				return n * (1 - discount) * price;
			else
				return n * price - quantity * discount * price;
		}
		virtual Lds_item* clone() const
		{
			return new Lds_item(*this);
		}
};

class Sales_item
{
	public:
		Sales_item() : p(0), use(new size_t(1)){}
		Sales_item(const Item_base &item):
			p(item.clone()), use(new size_t(1)){}
		Sales_item(const Sales_item &i)
			:p(i.p), use(i.use)
		{
			++*use;		
		}
		~Sales_item()
		{
			decr_use();
		}
		Sales_item & operator = (const Sales_item&);
		const Item_base *operator->() const
		{
			if(p)
				return p;
			else
				throw std::logic_error("unbound Sales_item");
		}
		const Item_base & operator*() const
		{
			if(p)
				return *p;
			else
				throw std::logic_error("unbound Sales_item");
		}
	private:
		Item_base *p;
		size_t *use;
		void decr_use()
		{
			if(--*use == 0)
			{
				delete p;
				delete use;
			}
		}
};
Sales_item&
Sales_item::operator=(const Sales_item& rhs)
{
	++*rhs.use;
	decr_use();
	p = rhs.p;
	use = rhs.use;
	return *this;
}

inline bool
compare(const Sales_item &lhs, const Sales_item &rhs)
{
	return lhs->book() < rhs -> book();
}

class Basket
{
		typedef bool (*Comp)(const Sales_item&, const Sales_item&);
	public:
		typedef multiset<Sales_item, Comp> set_type;
		typedef set_type::size_type size_type;
		typedef set_type::const_iterator const_iter;

		Basket() : items(compare){}

		void add_item(const Sales_item &item)
		{
			items.insert(item);
		}
		size_type size(const Sales_item &i) const
		{
			return items.count(i);
		}
		double total() const;
	private:
		multiset<Sales_item, Comp> items;
};
double Basket::total() const
{
	double sum = 0.0;
	for(const_iter iter = items.begin(); iter != items.end();
			iter = items.upper_bound(*iter))
	{
		sum += (*iter)->net_price(items.count(*iter));
	}
	return sum;
}

int main(int argc, char *argv[])
{
	Basket basket;
	Sales_item item1(Bulk_item("7-115-14554-7", 99, 20, 0.2));
	Sales_item item2(Item_base("7-115-14554-8", 39));
	Sales_item item3(Lds_item("7-115-14554-9", 39));
	Sales_item item4(Bulk_item("7-115-14554-7", 99, 20, 0.2));

	basket.add_item(item1);
	basket.add_item(item2);
	basket.add_item(item3);
	basket.add_item(item4);
	
	cout << basket.total() << endl;

	return 0;
}

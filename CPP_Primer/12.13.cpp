/************************************************************************* > File Name: 12.13.cpp
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Wed 18 Mar 2015 04:16:08 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

class Screen
{
	public:
		typedef string::size_type index;
		char get() const
		{
			return contents[cursor];
		}
		inline char get(index ht, index wd) const;
		
		index get_cursor() const;
		Screen(index hght, index wdth, const string &cntnts);

		Screen & move(index r, index c);
		Screen & set(char);
		Screen & display(ostream &os)
		{
			do_display(os);
			return *this;
		}
		const Screen & display(ostream &os) const
		{
			do_display(os);
			return *this;
		}
	private:
		string contents;
		index cursor;
		index height, width;
		void do_display(ostream &os) const
		{
			os << contents;
		}
};
Screen::Screen(index hght, index wdth, const string &cntnts):
	contents(cntnts), cursor(0), height(hght), width(wdth)
{
}
char Screen::get(index r, index c) const
{
	index row = r * width;
	return contents[row + c];
}
inline Screen::index Screen::get_cursor() const
{
	return cursor;
}

Screen &  Screen::move(index r, index c)
{
	index row = r * width;
	cursor = row + c;
	return *this;
}
Screen & Screen::set(char c)
{
	contents[cursor] = c;
	return *this;
}

int main(int argc, char *argv[])
{
	Screen myScreen(3, 3,"a");
	myScreen.move(4, 0).set('#').display(cout);
	return 0;
}

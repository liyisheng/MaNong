/*************************************************************************
    > File Name: Valid_Parentheses.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Fri 10 Apr 2015 07:52:00 PM PDT
 ************************************************************************/

#include<iostream>
#include<stack>
using namespace std;

bool isValid(string s)
{
	stack<char> charStack;	
	size_t i = 0;
	
	while(i != s.length())
	{
		char c = s[i];
		if(c != ')' && c != ']' && c != '}')
			charStack.push(c);
		else
		{
			if(charStack.size() == 0)
				return false;
			char pre = charStack.top();
			switch(c)
			{
				case ')':
					if(pre == '(')
						charStack.pop();
					else
						return false;
					break;
				case '}':
					if(pre == '{')
						charStack.pop();
					else
						return false;
					break;
				case ']':
					if(pre == '[')
						charStack.pop();
					else
						return false;
					break;
			}
		}
		++i;
	}
	if(charStack.size() == 0)
		return true;
	else
		return false;
}

int main(int argc, char *argv[])
{
//	string s = "{()[]([(((())))]) }";
	string s = "{()[]([(((())))])}";
	cout << isValid(s) << endl;
	return 0;
}

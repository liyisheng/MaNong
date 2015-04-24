/*************************************************************************
  > File Name: test2.cpp
  > Author: liyisheng
  > Mail: liyishengchn@gmail.com 
  > Created Time: Wed 22 Apr 2015 06:41:50 PM CST
 ************************************************************************/
#include<iostream>
#include<sstream>
#include<ios>
void print_state (const std::ios& stream) {

	std::cout << " good()=" << stream.good();
	std::cout << " eof()=" << stream.eof();
	std::cout << " fail()=" << stream.fail();
	std::cout << " bad()=" << stream.bad();
}
int main () {

	std::stringstream stream;
	stream.clear (stream.goodbit);
	std::cout << "goodbit:"; print_state(stream); std::cout << '\n';
	stream.clear (stream.eofbit);
	std::cout << " eofbit:"; print_state(stream); std::cout << '\n';
	stream.clear (stream.badbit);
	std::cout << stream.rdstate() << std::endl;
	stream.clear (stream.failbit);
	std::cout << " failbit:"; print_state(stream); std::cout << '\n';



	
	return 0;
}

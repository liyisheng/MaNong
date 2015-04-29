/*************************************************************************
    > File Name: environ.cpp
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: 2015年04月27日 星期一 12时49分41秒
 ************************************************************************/

#include<iostream>
#include<cstdlib>

extern char **environ;

int main(int argc, char *argv[])
{
	char **env = environ;

	while(*env)
	{
		std::cout << (*env) << std::endl;
		env++;
	}
	return 0;
}

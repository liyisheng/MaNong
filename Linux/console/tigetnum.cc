/*************************************************************************
    > File Name: tigetnum.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: 2015年04月28日 星期二 16时13分53秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<term.h>
#include<curses.h>
using namespace std;

int main(int argc, char *argv[])
{
	int nrows, ncolumn;

	int ret = setupterm(NULL, 1, (int *)0);
	if(!ret)
		perror("ERR");

	nrows = tigetnum("lines");
	ncolumn = tigetnum("cols");

	cout << nrows << ncloum << endl;
	return 0;
}

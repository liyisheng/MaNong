/*************************************************************************
    > File Name: setbuf.c
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Mon 22 Jun 2015 06:07:01 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>


int main()
{
	int c;
	char buf[BUFSIZ];


//	setbuf(stdout, malloc(BUFSIZ));

	setbuf(stdout, buf);

	while((c = getchar()) != EOF)
	{
		putchar(c);
	}

}

/*************************************************************************
    > File Name: select_example.c
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Fri 30 Jan 2015 04:22:06 AM CST
 ************************************************************************/
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/select.h>
#include<sys/time.h>

int
main(void)
{
	fd_set rfds;
	struct timeval tv;
	int retval;
	char buf[1024];
	
	FD_ZERO(&rfds);
	FD_SET(0, &rfds);

	tv.tv_sec = 5;
	tv.tv_usec = 0;

	retval = select(1, &rfds, NULL, NULL, &tv);

	if(-1  == retval)
		perror("select()");
	else if(retval)
	{
		printf("Data is available now. \n");
		printf("%d\n",FD_ISSET(0, &rfds));
		read(0, buf, sizeof(buf));
	}
	else
		printf("No Data within five seconds.\n");

	exit(EXIT_SUCCESS);
}

/*************************************************************************
    > File Name: connect1.c
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Mon 04 May 2015 03:35:17 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>


#include<mysql/mysql.h>

int main()
{
	MYSQL *connection;

	connection = mysql_init(NULL);
	if(!connection)
	{
		fprintf(stderr, "mysql_init failed\n");
		return EXIT_FAILURE;
	}

	connection = mysql_real_connect(connection, "server", "rick", "rick", "foo", 0, NULL, 0);

	if(connection)
		printf("Connection success\n");
	else
		printf("Connection failed\n");

	mysql_close(connection);

	return EXIT_SUCCESS;
}


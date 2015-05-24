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
	MYSQL my_connection;

	mysql_init(&my_connection);

	if(mysql_real_connect(&my_connection, "localhost", "rick", "erro", "foo", 0, NULL, 0))
	{
		printf("Connection success\n");
		mysql_close(&my_connection);
	}else
	{
		printf("Connection failed\n");
		if(mysql_errno(&my_connection))
		{
			fprintf(stderr, "Connection error %d : %s\n",
					mysql_errno(&my_connection), mysql_error(&my_connection));
		}
	}

	return EXIT_SUCCESS;
}


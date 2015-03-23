/*************************************************************************
  > File Name: sql_test.c
  > Author: liyisheng
  > Mail: liyishengchn@gmail.com 
  > Created Time: Sun 22 Mar 2015 12:00:07 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#include<mysql/mysql.h>

int main()
{

	MYSQL my_connection;
	MYSQL_RES *result;
	MYSQL_ROW row; 
	int r, num;  
	char *sql = "select * from usr_account";
	char *sql_stu = "select stu_id, stu_name, score_1 from student";
	mysql_init(&my_connection);


	if(mysql_real_connect(&my_connection, "192.168.101.129", "root", "root", "SMIS",3306,NULL,0))
	{

		mysql_set_character_set(&my_connection, "gbk");
		if( !mysql_query(&my_connection, sql_stu))
		{

			result = mysql_store_result(&my_connection);
			num = mysql_num_fields(result);  
			//			unsigned long *lengths = mysql_fetch_lengths(result);
			while(row = mysql_fetch_row(result))
			{

				for(r = 0; r < num; r++)
				{

					puts(row[r]);
				}
			}
			mysql_free_result(result);
		}
		mysql_close(&my_connection);
	}
	system("pause");
	return 0;
}

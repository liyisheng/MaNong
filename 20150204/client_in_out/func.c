/*************************************************************************
	> File Name: ./func.c
	> Author: Comst
	> Mail:750145240@qq.com 
	> Created Time: Wed 04 Feb 2015 03:17:06 PM CST
 ************************************************************************/
#include "client.h"
void P(int semid) 
{
	struct sembuf my_buf ;
	memset(&my_buf, 0, sizeof(my_buf) );
	my_buf.sem_num = 0 ;
	my_buf.sem_op = -1 ;
	my_buf.sem_flg = SEM_UNDO ;
	semop(semid, &my_buf, 1);
}
void V(int semid)
{
	struct sembuf my_buf ;
	memset(&my_buf, 0, sizeof(my_buf) );
	my_buf.sem_num = 0 ;
	my_buf.sem_op = 1 ;
	my_buf.sem_flg = SEM_UNDO ;
	semop(semid, &my_buf, 1);
	
}



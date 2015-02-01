/*************************************************************************
    > File Name: server.h
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Sun 01 Feb 2015 08:41:37 PM CST
 ************************************************************************/

#ifndef _SERVER_H
#define _SERVER_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/select.h>
#include<sys/time.h>
#include<limits.h>
#define FIFO_PATH "/home/lys/manong/20150201/select_fifo_cs/fifo"
#define FIFO_NAME "server.fifo"

typedef struct tag
{
	int m_id;
	int m_send;
	int m_recv;
	struct tag* m_next;
}Client, *pClient;




#endif

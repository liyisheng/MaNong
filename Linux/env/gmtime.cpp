/*************************************************************************
    > File Name: gmtime.cpp
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: 2015年04月27日 星期一 13时32分37秒
 ************************************************************************/

#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

int main(int argc, char *argv[])
{
	struct tm *tm_ptr;
	time_t the_time;


	time(&the_time);
	tm_ptr = gmtime(&the_time);

	cout << "Raw time is " << the_time << endl;

	cout << tm_ptr ->tm_year << " "<< tm_ptr ->tm_mon + 1 << " "<< tm_ptr ->tm_mday << endl;

	cout << tm_ptr->tm_hour  << " "<< tm_ptr->tm_min  << " "<< tm_ptr ->tm_sec << endl;
	return 0;
}

/*************************************************************************
    > File Name: mmap.cc
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Mon 20 Apr 2015 04:14:24 PM CST
 ************************************************************************/

#include<iostream>
#include<unistd.h>
#include<stdio.h>
#include<sys/mman.h>
#include<fcntl.h>
#include<stdlib.h>
using namespace std;


struct RECORD
{
	int integer;
	char string[24];
};

#define NRECORDS (100)
int main(int argc, char *argv[])
{
	RECORD record, *mapped;
	FILE *fp;

	fp = fopen("records.dat", "w+");
	for(int i = 0; i < NRECORDS; ++i)
	{
		record.integer = i;
		sprintf(record.string, "RECORD-%d", i);
		fwrite(&record, sizeof(record), 1, fp);
	}
	fclose(fp);

	int f = open("records.dat", O_RDWR);
	mapped = (RECORD*)mmap(0, NRECORDS*sizeof(record), PROT_READ|PROT_WRITE, MAP_SHARED, f, 0);
	mapped[43].integer = 243;
	sprintf(mapped[43].string, "RECORDS-%d", mapped[43].integer);

	msync((void*)mapped, NRECORDS*sizeof(record), MS_ASYNC);

	munmap((void*)mapped, NRECORDS*sizeof(record));
	close(f);
	return 0;
}

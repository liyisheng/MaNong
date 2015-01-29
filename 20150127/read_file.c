/*************************************************************************
 *         > File Name: read_file.c
 *         > Author: Comst
 *         > Mail:750145240@qq.com
 *         > Created Time: Tue 27 Jan 2015 10:24:26 AM CST
 *************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc, char* argv[])
{

	int fd_in = open(argv[1],O_RDONLY );
	int fd_out = open(argv[2], O_WRONLY | O_TRUNC);
	if(fd_in == -1)
	{
		perror("fail");
		exit(1);
	}
	if(fd_out == -1)
	{
		perror("out fail");
		exit(1);
	}
	printf("OK!\n");
	char buf[128] = "" ;
	int iret ;
	iret = read(0, buf, 127);
	//write(fd_out, buf, strlen(buf));
	write(1, buf, strlen(buf));

	printf("readn: %d\nbuf:%s\n", iret, buf);
	close(fd_in);
	close(fd_out);

	return 0 ;
}

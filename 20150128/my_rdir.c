/*************************************************************************
	> File Name: my_rdir.c
	> Author: Comst
	> Mail:750145240@qq.com 
	> Created Time: Wed 28 Jan 2015 03:56:59 PM CST
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<dirent.h>
#include<stdlib.h>
int main(int argc, char* argv[])
{

	DIR* fp_dir ;
	struct dirent* pent ;
	//chdir("..");
	fp_dir = opendir(argv[1]);
	if(fp_dir == NULL)
	{
		perror("open");
		exit(1);
	}
	printf("OK!\n");
	while((pent = readdir(fp_dir)) != NULL )
	{
		printf("ino: %u\noff_t:%u\nreclen:%u\nname: %s\ntype:%x\n" ,pent ->d_ino,pent ->d_off,pent ->d_reclen, pent ->d_name, pent ->d_type );
		printf("--------------------------------\n");
	}
	closedir(fp_dir);
	return 0 ;
}

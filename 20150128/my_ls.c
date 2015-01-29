/*************************************************************************
	> File Name: my_ls.c
	> Author: Comst
	> Mail:750145240@qq.com 
	> Created Time: Wed 28 Jan 2015 05:03:33 PM CST
 ************************************************************************/
#include"my_ls.h"
int main(int argc, char* argv[])
{

	DIR* fp_dir ;
	struct dirent* pent ;

	fp_dir = opendir(argv[1]);
	if(fp_dir == NULL)
	{
		perror("open");
		exit(1);
	}
	printf("OK!\n");
	while((pent = readdir(fp_dir)) != NULL )
	{
		show_info(pent ->d_name);
	}
	closedir(fp_dir);
	return 0 ;
}

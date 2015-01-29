/*************************************************************************
	> File Name: show_info.c
	> Author: Comst
	> Mail:750145240@qq.com 
	> Created Time: Wed 28 Jan 2015 05:08:19 PM CST
 ************************************************************************/
#include"my_ls.h"
static void mode_to_str(mode_t md, char* buf) ;
static char* time_handle(char* pt);
void show_info(char* path)
{
	struct stat my_stat ;
	char buf[11] ;
	memset(&my_stat, 0, sizeof(my_stat));
	if(-1 == stat(path, &my_stat))
	{
		perror("stat");
		exit(1);

	}
	mode_to_str(my_stat.st_mode, buf);
	printf("%s.%3d%8s%8s%5d %s %s\n", buf, my_stat.st_nlink, getpwuid(my_stat.st_uid) ->pw_name, getgrgid(my_stat.st_gid) -> gr_name, my_stat.st_size, time_handle( ctime(&my_stat.st_mtime) ), path);
	
}
static void mode_to_str(mode_t md, char* buf)
{
	if(S_ISREG(md))
	{
		buf[0] ='-' ;
	}else if(S_ISDIR(md))
	{
		buf[0] ='d';
	}else if(S_ISCHR(md))
	{
		buf[0] = 'c' ;
	}else if(S_ISBLK(md))
	{
		buf[0]='b';
	}else if(S_ISFIFO(md))
	{
		buf[0] = 'p';
	}else if(S_ISLNK(md))
	{
		buf[0] = 'l' ;
	}else
	{
		buf[0] = 's' ;
	}
	if(md & S_IRUSR)
	{
		buf[1] = 'r' ;
	}else
	{
		buf[1] = '-' ;
	}

	if(md & S_IWUSR)
	{
		buf[2] = 'w' ;
	}else
	{
		buf[2] = '-' ;
	}

	if(md & S_IXUSR)
	{
		buf[3] = 'x' ;
	}else
	{
		buf[3] = '-' ;
	}


	if(md & S_IRGRP)
	{
		buf[4] = 'r' ;
	}else
	{
		buf[4] = '-' ;
	}

	if(md & S_IWGRP)
	{
		buf[5] = 'w' ;
	}else
	{
		buf[5] = '-' ;
	}

	if(md & S_IXGRP)
	{
		buf[6] = 'x' ;
	}else
	{
		buf[6] = '-' ;
	}

	if(md & S_IROTH)
	{
		buf[7] = 'r' ;
	}else
	{
		buf[7] = '-' ;
	}

	if(md & S_IWOTH)
	{
		buf[8] = 'w' ;
	}else
	{
		buf[8] = '-' ;
	}
	if(md & S_IXOTH)
	{
		buf[9] = 'x' ;
	}else
	{
		buf[9] = '-' ;
	}
	buf[10] = 0;

}
static char* time_handle(char* pt)
{
	pt[strlen(pt) - 1] = 0 ;
	return pt + 4 ;
}

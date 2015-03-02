/*************************************************************************
	> File Name: server.c
	> Author: Comst
	> Mail:750145240@qq.com 
	> Created Time: Wed 04 Feb 2015 04:40:58 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<signal.h>
#define PATH "/home/comst/pipe"
#define NAME "server.fifo"

void child_handle(int sig_num)
{
	printf("a child exit!\n");
	wait(NULL);
}
void reverse(char* str)
{
	int bg, end ;
	char tmp ;
	bg = 0 ;
	end = strlen(str) - 1 ;
	while(bg < end)
	{
		tmp = str[bg] ;
		str[bg] = str[end] ;
		str[end] = tmp ;
		bg ++ ;
		end -- ;
	}

}
void child_main(int fd_rd, int fd_wr)
{
	char buf[1024] ;
	while(memset(buf, 0, 1024), read(fd_rd, buf, 1024) != 0)
	{
			reverse(buf);
			write(fd_wr, buf, strlen(buf));
	}

}
int main(int argc, char* argv[])
{
	signal(17, child_handle);
	char file_name[128]  = "";
	char client_r[128], client_w[128];
	char line[32] ;
	int fd_read ;
	int client_id ;
	int fd_cr , fd_cw ;
	FILE* fp ;
	sprintf(file_name, "%s/%s", PATH, NAME);
	mkfifo(file_name, 0666) ;
	fd_read = open(file_name, O_RDONLY);
	open(file_name, O_WRONLY);
	
	fp = fdopen(fd_read, "r");

	while(memset(line, 0 , 32), fgets(line, 32, fp) != NULL)// "pid\n"
	{// cr  cw pid_r.fifo  pid_w.fifo
		sscanf(line, "%d", &client_id);
		printf("client: %d request !\n", client_id) ;
		memset(client_r, 0, 128);
		memset(client_w, 0, 128);

		sprintf(client_r, "%s/%d_r.fifo", PATH, client_id);

		sprintf(client_w, "%s/%d_w.fifo", PATH, client_id);

		fd_cw = open(client_r, O_WRONLY);
		fd_cr = open(client_w, O_RDONLY);
		if(fork() == 0)
		{
			child_main(fd_cr, fd_cw);
			close(fd_cr);
			close(fd_cw);
			exit(1);
		}
		close(fd_cr);
		close(fd_cw);
	}



	
	memset(file_name, 0, 128);
	sprintf(file_name, "%s/%s", PATH, NAME);
	unlink(file_name);
	return 0 ;
}

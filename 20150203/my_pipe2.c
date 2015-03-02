/*************************************************************************
	> File Name: my_pipe.c
	> Author: Comst
	> Mail:750145240@qq.com 
	> Created Time: Tue 03 Feb 2015 03:04:50 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
void handle(char* str)
{
	int bg, end ;
	int tmp ;
	bg = 0; 
	end = strlen(str) - 1;
	while(bg < end)
	{
		tmp = str[bg] ;
		str[bg] = str[end] ;
		str[end] = tmp ;
		bg ++ ;
		end -- ;
	}
}
int main(int argc, char* argv[])
{
	int fds[2] ;// fds[0]_r fds[1]_w
	int fds1[2] ;
	pipe(fds) ;// p_s  c_r
	pipe(fds1) ;// p_r c_s
	pid_t pid ;
	pid = fork() ;
	if(pid > 0)
	{// send
		close(fds[0]);
		close(fds1[1]);
		char buf[1024] ;
		FILE* fp_out = fdopen(fds[1], "w") ;
		while(memset(buf, 0, 1024), fgets(buf, 1024, stdin) != NULL)
		{
			write(fds[1], buf, strlen(buf));
			memset(buf, 0, 1024);
			read(fds1[0], buf, 1024);
			printf("after handle: %s\n", buf);
		}
		close(fds[1]);
		close(fds1[0]);
		printf("waiting...!\n");
		wait(NULL) ;
		printf("wait return!\n");
	}else if(pid == 0)
	{//recv
			char recv_buf[1024] ;
			close(fds[1]);
			close(fds1[0]);
			while(memset(recv_buf, 0, 1024), read(fds[0], recv_buf, 1024) != 0)
			{
				handle(recv_buf);
				write(fds1[1], recv_buf, strlen(recv_buf));
			}
			close(fds1[1]);
			close(fds[0]);
	}
	return 0 ;
}

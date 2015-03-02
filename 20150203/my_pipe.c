/*************************************************************************
    > File Name: my_pipe.c
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Tue 03 Feb 2015 03:13:44 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int fds[2];
	pipe(fds);
	pid_t pid;
	pid = fork();

	if(pid > 0)
	{
		char buf[1024];
		close(fds[0]);
		while(memset(buf, 0, 1024), fgets(buf, 1024, stdin) != NULL)
		{
			write(fds[1], buf, strlen(buf));
		}
	//	close(fds[0]);
		close(fds[1]);
		printf("waiting...\n");
		wait(NULL);
		printf("wait return \n");
	}else if(pid == 0)
	{
		char recv_buf[1024];
		close(fds[1]);
		while(memset(recv_buf, 0, 1024), read(fds[0], recv_buf, 1024) != 0)
		{
			printf("from parent: %s", recv_buf);
		}
		close(fds[0]);
//		close(fds[1]);  //fork拷贝了一份fds, 则需要先关闭fds[1]写端， while循环才能退出
	}

	return 0;
}

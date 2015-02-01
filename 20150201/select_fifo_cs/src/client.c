/*************************************************************************
    > File Name: client.c
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Mon 02 Feb 2015 12:31:21 AM CST
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/select.h>
#include<sys/time.h>
#include<sys/ioctl.h>
#define PIPE_PATH "/home/lys/manong/20150201/select_fifo_cs/fifo"
#define PIPE_NAME "server.fifo"
int main(int argc, char* argv[])
{
	int retval;
	int fd_server , nread;
	char path_name_r[128]="";
	char path_name_w[128]="";
	char path_name[128]="";
	char fifo_name[128] ;
	char msg[1024] ="" ;
	char logstat[1024] = "";
	int fd_recv, fd_send ;
	fd_set rd_sets ;
	sprintf(path_name, "%s/%s", PIPE_PATH, PIPE_NAME);

	fd_server = open(path_name, O_WRONLY);
	if(fd_server == -1)
	{
		printf("open fail!\n");
		exit(1) ;
	}
//需要先创建管道文件， 再发送消息到服务端 ,否则服务端收到消息后打开管道文件出错
	memset(fifo_name, 0,  sizeof(fifo_name));
	sprintf(fifo_name, "%u_r.fifo", getpid());
	memset(path_name_r, 0, sizeof(path_name_r));
	sprintf(path_name_r, "%s/%s", PIPE_PATH, fifo_name);
	retval = mkfifo(path_name_r, 0777);
	if( retval == -1)
	{
		perror("mkfifo");
		exit(1);
	}

	memset(fifo_name, 0,  sizeof(fifo_name));
	sprintf(fifo_name, "%u_w.fifo", getpid());
	memset(path_name_w, 0, sizeof(path_name_w));
	sprintf(path_name_w, "%s/%s", PIPE_PATH, fifo_name);

	retval = mkfifo(path_name_w, 0777);
	if( retval == -1)
	{
		perror("mkfifo");
		exit(1);

	}
	//登陆 传信息到服务端
	memset(logstat, 0, sizeof(logstat));
	sprintf(logstat, "%u on\n", getpid());
	printf("logstat: %s\n", logstat);
	write(fd_server, logstat, strlen(logstat));



//	printf("%s\n", path_name_r);
	fd_recv = open(path_name_r, O_RDONLY);


//	printf("%s\n", path_name_w);
	fd_send = open(path_name_w, O_WRONLY);

	printf("fifo open %d %d\n", fd_send, fd_recv);

	FD_ZERO(&rd_sets);
	while(1)
	{
		FD_SET(0, &rd_sets);
		FD_SET(fd_recv, &rd_sets);

		select(1024, &rd_sets, NULL, NULL, NULL);

			if(FD_ISSET(0, &rd_sets))
			{
				ioctl(0, FIONREAD, &nread);
				if(nread == 0)
				{
					printf("logout\n");
					//登陆 传信息到服务端
					memset(logstat, 0, sizeof(logstat));
					sprintf(logstat, "%u off\n", getpid());
					printf("logstat: %s\n", logstat);
					write(fd_server, logstat, strlen(logstat));
					close(fd_send);
					exit(1);
				}
				memset(msg, 0, sizeof(msg)) ;
				sprintf(msg, "%u: ", getpid());
				read(0, msg + strlen(msg),  1024 - strlen(msg) );
//				printf("msg to send :%s\n", msg);
				write(fd_send, msg, strlen(msg));
			}
			if(FD_ISSET(fd_recv, &rd_sets))
			{
				memset(msg, 0, sizeof(msg)) ;
				read(fd_recv, msg, 1024);
				write(1, msg, strlen(msg));
			}
	}

}

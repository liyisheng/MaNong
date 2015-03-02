/*************************************************************************
  > File Name: client_in.c
  > Author: Comst
  > Mail:750145240@qq.com 
  > Created Time: Wed 04 Feb 2015 03:04:39 PM CST
 ************************************************************************/
#include "client.h"
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/fcntl.h>
#define PATH "/home/comst/pipe"
#define SERVER "server.fifo"
int main(int argc, char* argv[])//shm_key sem_key
{

	char server_name[128]= "" ;
	char read_file[128], write_file[128] ;
	char msg[32] ="" ;
	int fd_r, fd_w ;
	sprintf(server_name, "%s/%s", PATH, SERVER);
	int fd_server = open(server_name, O_WRONLY);

	memset(read_file, 0, 128);
	memset(write_file, 0, 128);

	sprintf(read_file, "%s/%d_r.fifo", PATH, getpid());
	sprintf(write_file, "%s/%d_w.fifo", PATH, getpid());

	mkfifo(read_file, 0666);
	mkfifo(write_file, 0666);

	sprintf(msg, "%d\n", getpid());
	write(fd_server, msg, strlen(msg));


	fd_r = open(read_file, O_RDONLY);
	fd_w = open(write_file, O_WRONLY);


	key_t shm_key, sem_key ;
	int my_shm, my_sem ;

	char line[1024] ;

	pMBUF p ;
	shm_key = (key_t)atoi(argv[1]);
	sem_key = (key_t)atoi(argv[2]);

	my_shm = shmget(shm_key, sizeof(MBUF), 0666|IPC_CREAT);

	my_sem = semget(sem_key, 1, 0666 | IPC_CREAT);
	semctl(my_sem, 0, SETVAL, 1);


	p = (pMBUF)shmat(my_shm, NULL, 0);
	memset(p, 0, sizeof(MBUF));

	while(memset(line, 0, 1024), fgets(line, 1024, stdin) != NULL)
	{
		write(fd_w, line, strlen(line));

		memset(line, 0, 1024);

		read(fd_r, line, 1024);
		while( P(my_sem), p -> m_flag == 1)
		{
			V(my_sem);
			sleep(1);
		}
		strcpy(p ->m_buf, line);
		p ->m_flag = 1 ;
		V(my_sem);

	}

	while( P(my_sem), p -> m_flag == 1)
	{
		V(my_sem);
		sleep(1);
	}
	strcpy(p ->m_buf, "over");
	p ->m_flag = 1 ;
	V(my_sem);

	sleep(3);




	shmdt(p);
	shmctl(my_shm, IPC_RMID, NULL) ;

	semctl(my_sem, 0, IPC_RMID);



}



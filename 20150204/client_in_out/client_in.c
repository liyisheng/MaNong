/*************************************************************************
  > File Name: client_in.c
  > Author: Comst
  > Mail:750145240@qq.com 
  > Created Time: Wed 04 Feb 2015 03:04:39 PM CST
 ************************************************************************/
#include "client.h"
int main(int argc, char* argv[])//shm_key sem_key
{
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



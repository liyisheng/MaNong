/*************************************************************************
    > File Name: server.c
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Sun 01 Feb 2015 08:29:59 PM CST
 ************************************************************************/
#include<server.h>

int main(int argc, char *argv[])
{
	int retval, fd_listen, client_pid;	
	char path_name[128] = "";
	char fifo_name[128] = "";
	fd_set  rd_sets, bak_sets;
	pClient plist = NULL, pNew, pPre, pCur, pTemp;

	char msg[1024];
	char logstat[1024];
	char client_stat[5] = "";

	sprintf(path_name, "%s/%s", FIFO_PATH, FIFO_NAME);
	if(access(path_name, F_OK) == -1)
	{
		retval = mkfifo(path_name, 0777);
		if(retval != 0)
		{
			fprintf(stderr, "Could not creat fifo %s\n", path_name);
			exit(EXIT_FAILURE);
		}
	}

	fd_listen = open(path_name, O_RDONLY);
	if(fd_listen == -1)
	{
		perror("open server_info");
		exit(EXIT_FAILURE);
	}

	FD_ZERO(&rd_sets);
	FD_ZERO(&bak_sets);
	FD_SET(fd_listen, &rd_sets);

	while(1)
	{
		bak_sets = rd_sets;
		printf("selecting...\n");

		retval = select(1024, &bak_sets, NULL, NULL, NULL);
		if( -1 == retval)
		{
			perror("select");
			exit(1);
		}	
		if(FD_ISSET(fd_listen, &bak_sets))
		{
			memset(logstat, 0, sizeof(logstat));
			retval = read(fd_listen, logstat, 1024);
			if(retval == 0)	
			{
				printf("no clients!\n");
				sleep(5);
				continue;	
			}
			
			memset(client_stat, 0, sizeof(client_stat));
			sscanf(logstat, "%d%s", &client_pid, client_stat);
			if(strncmp("on", client_stat, 2) == 0)  //client on
			{
				printf("client: %d on \n", client_pid);
				memset(fifo_name, 0, sizeof(fifo_name));
				sprintf(fifo_name, "%d_r.fifo", client_pid);
				memset(path_name, 0, sizeof(path_name));
				sprintf(path_name, "%s/%s", FIFO_PATH, fifo_name);

				pNew = (pClient)calloc(1, sizeof(Client));
				pNew->m_id = client_pid;
				printf("pid_r.fifo: %s\n", path_name);
				pNew->m_send = open(path_name, O_WRONLY);
				printf("send_fd: %d\n", pNew->m_send);
				
				memset(fifo_name, 0, sizeof(fifo_name));
				sprintf(fifo_name, "%d_w.fifo", client_pid);
				memset(path_name, 0, sizeof(path_name));
				sprintf(path_name, "%s/%s", FIFO_PATH, fifo_name);

				printf("pid_r.fifo: %s\n", path_name);
				pNew->m_recv = open(path_name, O_RDONLY);
				printf("recv_fd: %d\n", pNew->m_recv);

				FD_SET(pNew->m_recv, &rd_sets);
				
				//客户端信息 头插 置入链表
				pNew->m_next = plist;
				plist = pNew;
			}else
			{
				printf("client: %d off\n", client_pid);
				pPre = NULL;
				pCur = plist;
				while(pCur && pCur->m_id != client_pid)
				{
					pPre = pCur;
					pCur = pCur->m_next; 
				}

				if(pCur == NULL)
				{
					printf("not exit!\n");
					continue;
				}else
				{
					if(pPre == NULL)	
						plist = pCur ->m_next;
					else
					{
						pPre->m_next = pCur->m_next;
					}
					close(pCur->m_send);
					close(pCur->m_recv);
					FD_CLR(pCur->m_recv, &rd_sets);
					free(pCur);
					printf("clear ok!\n");
				}
			}	
		}
		pCur = plist;
		pTemp = plist;
		while(pCur)
		{
			if(FD_ISSET(pCur ->m_recv, &bak_sets))
			{
				memset(msg, 0, sizeof(msg));
				read(pCur-> m_recv, msg, 1024);
				printf("%s\n", msg);
				while(pTemp)		
				{
					if(pTemp == pCur)
						;	
					else
						write(pTemp ->m_send, msg, strlen(msg));
					pTemp = pTemp ->m_next;
				}
			}
			pCur = pCur ->m_next;
		}

	}//while


	return 0;
}


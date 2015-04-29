/*************************************************************************
    > File Name: memory3.c
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: 2015年04月29日 星期三 13时57分21秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define  A_MEGABYTE (1024 * 1024)
#define ONE_K (1024)
#define PHY_MEM_MEGS (1024 * 4)

int main()
{
	char *some_memory;
	size_t size_to_allocate = ONE_K;
	int megs_obtained = 0;
	int ks_obtained = 0;
	while(1)
	{
		for(ks_obtained = 0; ks_obtained < 1024; ks_obtained++)
		{
			some_memory = (char *)malloc(size_to_allocate);
			if(some_memory  != NULL)
				sprintf(some_memory, "Hello World!\n");
			else
				exit(EXIT_FAILURE);
		}
		megs_obtained++;
		printf("%s - now allocated %d Megabytes\n", some_memory, megs_obtained );
		
	}
	exit(EXIT_SUCCESS);
}

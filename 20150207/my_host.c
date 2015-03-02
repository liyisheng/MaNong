/*************************************************************************
	> File Name: my_host.c
	> Author: Comst
	> Mail:750145240@qq.com 
	> Created Time: Sat 07 Feb 2015 05:23:46 PM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<netdb.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
int main(int argc, char* argv[])
{
	struct hostent* pent ;
	int i ;
	pent = gethostbyname(argv[1]) ;
	if(pent == NULL)
	{
		perror("host");
	}
	printf("h_name: %s\n", pent ->h_name);
	for(i = 0; pent ->h_aliases[i] != NULL; i ++)
	{
		printf("aliase %d: %s\n", i, pent ->h_aliases[i]);
	}
	printf("addr_type: %d, len: %d\n", pent ->h_addrtype, pent ->h_length );
	for(i = 0; pent ->h_addr_list[i] != NULL; i ++)
	{

		//printf("ip %d: %s\n ", i, inet_ntoa( *(struct in_addr*)pent ->h_addr_list[i]) );
		printf("ip %d: %s\n ", i, inet_ntoa( *(struct in_addr*)pent ->h_addr_list[i] ));
	}

	return 0 ;
}

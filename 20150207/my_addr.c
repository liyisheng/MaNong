/*************************************************************************
	> File Name: my_atoh.c
	> Author: Comst
	> Mail:750145240@qq.com 
	> Created Time: Sat 07 Feb 2015 04:56:54 PM CST
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#define IP "180.97.33.107"// B461216B
int main(int argc, char* argv[])
{

	struct in_addr addr ;
	memset(&addr, 0, sizeof(addr));
	inet_aton(IP, &addr);
	memset(&addr, 0, sizeof(addr));
	addr.s_addr = inet_addr(IP);
	char* pstr = inet_ntoa(addr);
		
	return 0 ;
}


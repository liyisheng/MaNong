#include<stdio.h>
#include<stdlib.h>

#define BASE 8
/*小端字节序 -> 大端字节序*/
int main()
{
    int a = 0x12345678; 
    int result = 0;
    int i = 0;
    printf("%x\n",a);
    while( i < 4) 
    {
	result |= (a & 0x00ff) << (3-i)*BASE;
	a >>= BASE;
	i++;
    }
    printf("%x\n", result);
    return 0;
}

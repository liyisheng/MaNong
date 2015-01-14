#include<stdio.h>
#include<stdlib.h>


int countOne(unsigned n)
{
    int count = 0; 
    while(n)
    {
	if(n & 0x1)
	    count++; 
	n >>= 1;
    }
    return count;
}


int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", countOne(n));
    return 0;
}

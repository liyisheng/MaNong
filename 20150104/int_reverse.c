#include<stdio.h>
#include<stdlib.h>


int main()
{
    int n = 12345;
    int sum = 0;
    printf("before : %d\n", n); 
   
    while(n)
    {
	sum = 10*sum + n%10;
	n /= 10;
    } 
    printf("now : %d\n", sum);
    return 0;

} 

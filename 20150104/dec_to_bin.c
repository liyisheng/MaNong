#include<stdio.h>
#include<math.h>
int main()
{
    int dec,bin = 0;
    int i = 0;
    int j = 0;
    int x = 1;
    scanf("%d", &dec);
    
    while(dec)
    {
	x = 1;
	for(j = 0; j < i; j++)
	    x *= 10;   
	bin += (dec%2)*x;
	dec /= 2;
	i++;
    }
    printf("%d\n", bin);
   
     
    
    return 0;
}



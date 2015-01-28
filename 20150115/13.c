#include<stdio.h>
#include<stdlib.h>

int FindUniq(int a[], int len)
{
    int i,j;
//    for(i = 0; i < len; i++)
    for(i = 0; i < len; i++)	
    {
	for(j = 0; j < len; j++)	
	    if(j != i && a[j] == a[i])
		break;
	    if(j == len)
		return a[i];
    }
    return 0;
}


int FindUniq_XOR(int a[], int len)
{
    int i;
    for(i = 1; i < len; i++)
    {
	a[i] ^= a[i - 1];  
    }
    return a[i - 1];
}

int main()
{
    int a[] = {11, 22, 33, 44, 55, 66, 77 ,88, 99, 111, 111, 999, 99, 88, 77, 66, 55, 44, 33, 22, 11};
//    printf("%d\n", FindUniq_XOR(a, 21));
    printf("%d\n", FindUniq(a, 21));
    return 0;
}

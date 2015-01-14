#include<stdio.h>



int de_repeat(int a[], int len)
{
    int i;
    int k = 1;
    int key = a[0];
    for(i = 1 ; i < len; i++)
    {
	if(a[i] != key)	
	{
	    a[k] = a[i];
	    key = a[k];
	    k++;
	}
    }
    return k;
}


int main()
{
    int a[] = {1,2,2,2,3,3,3,4,4,5,5,5,6,6};
    int i;
    int k = de_repeat(a, 14);
    for(i = 0; i < k; i++)
    printf("%d ",a[i]);
    printf("\n");
    return 0;
}

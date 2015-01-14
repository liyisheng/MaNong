#include<stdio.h>
#include<stdlib.h>
#define  N 100

void insertion_sort(int *a, int len);

/*
   n个整型数组  
   b中存放各数组的长度
 */
int fun(int (*a)[N], int n, int b[]) 
{
    int i;
    int k = b[0];
    for(i = 1; i < n; i++)
    {
	k = fun2(a[0],a[i],k,b[i]);
    }
    return k;
}

int fun2(int *a, int *b,int na, int nb)
{
    int i,j,k = 0;
    int c[N] = {0};
    insertion_sort(a, na);
    insertion_sort(b, nb); 
    for(i = 0,j = 0; i < na && j < nb; )
    {	
	if(a[i] == b[j])		
	{
	    c[k] = a[i];
	    k++;
	    i++;
	    j++;
	}else if(a[i] < b[j])
	{
	    i++; 
	}else
	    j++;   
    }

    for(i = 0; i < k; i++)
	a[i] = c[i];
    return k;
}
/*
1 1 1 2 3 5 5
1 1 2 3 4
*/

void insertion_sort(int *a, int len)
{
    int i, j, key;
    for(i = 1; i < len; i++)
    {
	key = a[i];
	j = i - 1;
	while(j >= 0 && a[j] > key)
	{
	    a[j + 1] = a[j];
	    j--;
	}
	a[j + 1] = key;
    }	
}


int main()
{
    int i;
    int ap[][N] = {{1,1,1,2,3,4,5,6,7,8,9,10}, {1,1,2,3,4,5,7,8,10}, {1,2,3,4,5,6,8}, {1,2,3,4,5,6,7,9,10}};

    int len[] = {12,9,7,9};
    int length = fun(ap,4,len);


    for(i = 0; i < length; i++)
    {
	printf("%d  ",ap[0][i]);
    }
    printf("\n");
    return 0;
}

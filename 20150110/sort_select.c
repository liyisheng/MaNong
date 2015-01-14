#include<stdio.h>
#include<time.h>

#define SIZE 101

void array_show(int *a, int len);
void array_init(int *a,int len);
void sort_select(int *a, int len);

int main()
{
    clock_t begin,end;
    double cost;

    int a[SIZE]; 
    array_init(a,SIZE);
    array_show(a,SIZE);

    begin = clock();

    sort_select(a,SIZE);

    end = clock();
    cost = (double)(end - begin)/CLOCKS_PER_SEC;
    array_show(a,SIZE);

    printf("%f\n",cost);

    return 0;
}

void array_init(int *a,int len)
{
    int i; 
    for(i = 0; i < len; i++)
	a[i] = rand()%100;
}
void array_show(int *a, int len)
{
    int i; 
    for(i = 0; i < len; i++)
	printf("%d ", a[i]);
    printf("\n");
}

void sort_select(int *a, int len)
{
    int i,idx,tmp;
    int max_idx;

    for(i = 0; i < len; i++)
    {
	max_idx = 0;

	for(idx = 0; idx < len -i; idx++) 
	{
	    if(a[idx] > a[max_idx])
		max_idx = idx;
	}
	tmp = a[max_idx];
	a[max_idx] = a[len - 1 - i];
	a[len - 1 - i] = tmp;
    }
}


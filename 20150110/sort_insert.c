#include<stdio.h>
#include<time.h>

#define SIZE 10000

void array_show(int *a, int len);
void array_init(int *a,int len);
void sort_insert(int *a, int len);
void sort_shell(int *a, int len);

int main()
{
    clock_t begin,end;
    double cost;

    int a[SIZE]; 
    array_init(a,SIZE);
    array_show(a,SIZE);

    begin = clock();

    sort_insert(a,SIZE);

    end = clock();
    cost = (double)(end - begin)/CLOCKS_PER_SEC;
    array_show(a,SIZE);
    printf("%f\n",cost);

    array_init(a,SIZE);
    array_show(a,SIZE);
    begin = clock();

    sort_shell(a,SIZE);

    end = clock();
    cost = (double)(end - begin)/CLOCKS_PER_SEC;
    array_show(a,SIZE);

    printf("%f\n",cost);

    return 0;
}

void array_init(int *a,int len)
{
    srand(time(NULL));
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

void sort_insert(int *a, int len)
{
    int i,j; 
    int key;
    for(i = 1; i < len; i++)
    {
	key = a[i];
	for(j = i - 1; j >= 0 && a[j] > key; j--)
	{
	    a[j + 1]  = a[j];
	}
	a[j + 1] = key;
    }
}

void sort_shell(int *a, int len)
{
    int gap, i, j, temp;
    for(gap = len/2; gap > 0; gap /= 2)
	for(i = gap; i < len; i++)
	{
	    temp = a[i];
	    for(j = i - gap; j >= 0 && temp < a[j]; j -= gap)
		a[j + gap] = a[j];
	    a[j + gap] = temp;
	}
}

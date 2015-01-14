#include<stdio.h>
#include<time.h>

#define SIZE 1000

void sort_insert(int *a, int len);
void array_show(int *a, int len);
void array_init(int *a,int len);
void sort_quick(int *a, int len);

int main()
{
    clock_t begin,end;
    double cost;

    int a[SIZE]; 
    array_init(a,SIZE);
    array_show(a,SIZE);

    begin = clock();

    sort_quick(a,SIZE);

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

void sort_quick(int *a, int len)
{
    int k;
    if(len < 5)
    {
	sort_insert(a, len);
	return;
    }
    k = quick_partion(a, len);
    sort_quick(a, k);
    sort_quick(&a[k+1], len - k - 1);
}

int quick_partion(int *a, int len)
{
    int low, high;
    int key = a[0]; 
    low = 0;
    high = len -1;
    while(low < high)
    {
	for(;high > low && a[high] >= key; high--)
	    ;
	a[low] = a[high];
	for(;low < high && a[low] < key; low++)
	    ;
	a[high] = a[low];
    }
    a[low] = key;
    return low;
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


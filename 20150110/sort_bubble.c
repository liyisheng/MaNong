#include<stdio.h>
#include<time.h>

#define SIZE 13

void array_show(int *a, int len);
void array_init(int *a,int len);
void sort_bubble(int *a, int len);
void sort_bubble_2(int *a, int len);

int main()
{
    clock_t begin,end;
    double cost;

    int a[SIZE]; 
    array_init(a,SIZE);
    array_show(a,SIZE);

    begin = clock();

    sort_bubble_2(a,SIZE);

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

void sort_bubble(int *a, int len)
{
    int i,j; 
    int tmp;
    for(i = 1; i < len; i++)
	for(j = 0; j < len - i; j++)
	    if(a[j] > a[j + 1]) 
	    {
		tmp = a[j];
		a[j] = a[j + 1];
		a[j + 1] = tmp;
	    }
}

void sort_bubble_2(int *a, int len)
{
    int i, tmp;
    int up, down;
    up = 0;
    down =  len - 1;
    while(up <= down)
    {
	for(i = up; i < down; i++)
	{
	    if(a[i] > a[i + 1])
	    {
		tmp = a[i];
		a[i] = a[i + 1];
		a[i + 1] = tmp;
	    }
	}
	down--;
	for(i = down; i > up; i--)
	{
	    if(a[i] < a[i - 1])
	    {
		tmp = a[i];
		a[i] = a[i - 1];
		a[i - 1] = tmp;
	    }
	}
	up++;
    }
}

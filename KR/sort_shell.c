#include<stdio.h>
#define SIZE 10

void shell_sort(int s[], int len);
void array_show(int *a, int len);
void array_init(int *a,int len);
void shell_sort(int s[], int len)
{
    int gap, i, j, temp;
    for(gap = len/2; gap > 0; gap /= 2)
	for(i = gap; i < len; i++)
	    for(j = i - gap; j >= 0 && s[j] > s[j + gap]; j-= gap)
	    {
		temp = s[j];
		s[j] = s[j + gap];
		s[j + gap] = temp;
	    }
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

                   
int main()
{
    int a[SIZE];
    array_init(a,SIZE);
    array_show(a,SIZE);
    shell_sort(a,SIZE);
    array_show(a,SIZE);
    return 0;
}

   

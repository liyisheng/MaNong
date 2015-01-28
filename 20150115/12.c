#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
#include<stdlib.h>
#include<time.h>
#define M 10
#define N 10



void MaxNum(int **arr, int *max, int *min) 
{
    int i,j;
    *max = *min = arr[0][0];
    for(i = 0; i < M; i++)
	for(j = 0; j < N; j++)
	{
	    if(arr[i][j] > *max) 
		*max = arr[i][j];
	    if(arr[i][j] < *min)
		*min = arr[i][j];
	}    
}


int **arr_init(int row, int col)
{
    int i,j;
    int **arr = (int **)calloc(row, sizeof(int *));
    srand(time(NULL));
    for(i = 0; i < row; i++)
    {
	arr[i] = (int *)calloc(col, sizeof(int));
    }
    for(i = 0; i < row; i++)
	for(j = 0; j < col; j++)
	    arr[i][j] = rand()%1000;

    return arr;
}

void arr_destroy(int **arr, int row)
{
    int i;
    for(i = 0; i < row; i++)
    {
	free(arr[i]);
	arr[i] = NULL;
    }
    free(arr);
}

void arr_print(int **arr, int row, int col)
{
    int i,j;
    for(i = 0; i < row; i++)
    {
	for(j = 0; j < col; j++)
	    printf("%4d",arr[i][j]);
	printf("\n");
    }
    printf("\n");
}

int main()
{
    int max, min;
    int **arr = arr_init(M, N);
    MaxNum(arr, &max, &min);
    arr_print(arr, M, N);
    printf("%d %d\n", max, min);
    arr_destroy(arr, M);

}

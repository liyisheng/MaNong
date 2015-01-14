#include<stdio.h>
#include<stdlib.h>
/*
   打印蛇形矩阵 螺旋矩阵 斜矩阵
 */


char **array_init(int row, int col);
void array_destroy(char **arr, int row);
void array_snake(char **arr, int row, int col);
void array_print(char **arr, int row, int col);
void array_diagonal(char **arr, int row, int col);
void array_spiral(char **arr, int row, int col);

int main()
{
    int row, col;
    while(printf("row , col :"),scanf("%d%d", &row, &col))
    {
	char **arr = array_init(row ,col); 
//	array_snake(arr, row, col);
//	array_diagonal(arr, row, col);
	array_spiral(arr, row, col);
	array_print(arr, row, col);
	array_destroy(arr, row);
	arr = NULL;
    }
}

char **array_init(int row, int col)
{
    int i;
    char **arr = (char **)calloc(row, sizeof(char *));
    for(i = 0; i < row; i++)
    {
	arr[i] = (char *)calloc(col, sizeof(char));
    }
    return arr;
}

void array_destroy(char **arr, int row)
{
    int i;
    for(i = 0; i < row; i++)
	free(arr[i]);
}

void array_print(char **arr, int row, int col)
{
    int i, j;
    for(i = 0; i < row; i++)
    {
	for(j = 0; j < col; j++)
	    printf("%3d", arr[i][j]);
	printf("\n");
    }
    printf("\n");
}

void array_snake(char **arr, int row, int col)
{
    int i, j;   
    int count = 0;
    for(i = 0; i < row; i++)
	if(i%2 == 0)
	    for(j = 0; j < col; j++)
		arr[i][j] = ++count;
	else
	    for(j = col - 1; j > -1; j--)
		arr[i][j] = ++count;
}
/*
11 19 20 24 25
10 12 18 21 23
4  9  13 17 22
3  5  8  14 16
1  2  6  7  15
   */
void array_diagonal(char **arr, int row, int col)
{
    int i, j, count = 0;
    int line = 1; 
    int delt;
    for(line = 1; line <= row; line ++)
    {
	delt = row - line;
	if(line % 2 == 1)
	{
	    for(i = 0; i < row; i++)	
		for(j = 0; j <= i; j++) 	
		    if(j == i - delt)
			arr[i][j] = ++count;

	}else
	{
	    for(i = row - 1; i >= 0; i--)
		for(j = i; j >=0; j--)
		    if(j == i - delt)
			arr[i][j] = ++count;
	}
    }

    for(line = 1; line < col; line++)
    {
	delt = line;	
//	if(row % 2 == 1)
	if(line % 2 == !(row%2)) //奇数行与偶数行的  右半部分 开始的顺序不一样
	{
	    for(i = 0; i <= row - 1; i++)
		for(j = line + i; j < col; j++)
		    if(j == i + delt)
			arr[i][j]  = ++count;
	}else
	{
	    for(i = row - 1; i >= 0; i--)
		for(j = col - 1; j >= line + i; j--)
		    if(j == i + delt)
			arr[i][j] = ++count;

	}

    }
}

/*
 17 16 15 14 13
 18 5  4  3  12
 19 6  1  2  11
 20 7  8  9  10
 21 22 23 24 25
*/
void array_spiral(char **arr, int row, int col)
{
    
    int i, j, step_count;
    int count = 1;
    int step = 1;
    i = row >> 1;       
    j = col >> 1;
    if(row % 2 == 0)
	j--;
    arr[i][j] = 1; 
    while( count <= row * col)
    {
	//l -> r
	for(step_count = 0; step_count < step; step_count++, j++)
	    arr[i][j + 1] = ++count;
	if(count >= row * col)
	    break ;
	// d -> u 
	for(step_count = 0; step_count < step; step_count++, i--)
	    arr[i - 1][j] = ++count;	
	step++;
	// r -> l
	for(step_count = 0; step_count < step; step_count++, j--)
	    arr[i][j - 1] = ++count;
	if(count >= row * col)
	    break ;
	// u -> d
	for(step_count = 0; step_count < step; step_count++, i++)
	    arr[i + 1][j] = ++count;
	step++;
    }
}




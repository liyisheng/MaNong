/*************************************************************************
    > File Name: 03_FindInPartiallySortedMatrix.cpp
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Fri 19 Jun 2015 01:55:30 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

bool Find(int (*matrix)[4], int rows, int columns, int number);
bool Find2(int * matrix, int rows, int columns, int number);

int main(int argc, char *argv[])
{
	int a[4][4] = {
		1, 2, 8, 9,
		2, 4, 9, 12,
		4, 7, 10, 13,
		6, 8, 11, 15
	};
	cout << Find(NULL, 4, 4, 88) << endl;
	cout << Find2((int *)a, 4, 4, 7) << endl;
	return 0;
}

bool Find(int (*matrix)[4], int rows, int columns, int number)
{
	bool found = false;
	int row = 0;
	int column = columns - 1;
	if(matrix != NULL && rows > 0 && columns > 0)
	{
		while(row < rows && column >= 0)
		{
			if(matrix[row][column] == number)
			{
				found = true;
				break;
			}else if(matrix[row][column] > number)
				-- column;
			else
				++ row;
		}
	}
	return found;
}


bool Find2(int * matrix, int rows, int columns, int number)
{
	bool found = false;
	int row = 0;
	int column = columns - 1;
	if(matrix != NULL && rows > 0 && columns > 0)
	{
		while(row < rows && column >=0 )
		{
			if(matrix[row * columns + column] == number)
			{
				found = true;
				break;
			}else if(matrix[row * columns + column ] > number)
				-- column;
			else
				++ row;
		}
	}
	return found;
}

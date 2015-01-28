/*************************************************************************
    > File Name: CrossList.c
    > Author: liyisheng
    > Mail: liyishengchn@gmail.com 
    > Created Time: Mon 26 Jan 2015 08:08:21 PM CST
 ************************************************************************/
#include<func.h>

void CreateCrossList(CrossLink *l, int m, int n)
{
	int i;
	l->m = m, l->n = n; l->len = 0;
	l->row_head = (OLink*)malloc( m * sizeof(OLink));  
	l->col_head = (OLink*)malloc( n * sizeof(OLink));

	for(i = 0; i < m; i++)
	{
		l->row_head[i] = (OLink)malloc(sizeof(Node));
		l->row_head[i]->right = NULL;
	}
	for(i = 0; i < n; i++)
	{
		l->col_head[i] = (OLink)malloc(sizeof(Node));
		l->col_head[i]->down = NULL;
	}
}

int InsertCrossList(CrossLink *l, int row, int col, char *data)
{
	pNode p, q;
	p = (pNode)malloc(sizeof(Node));
	p->row = row, p->col = col;
	strcpy(p->name, data);	

	q = l->row_head[row];
	while( q->right != NULL && q->right->col < col) //根据列号查找行链表中位置
		q = q->right;  
	p->right = q->right;
	q->right = p;

	q = l->col_head[col];
	while(q->down != NULL && q->down->row < row)
		q = q->down;
	p->down = q->down;
	q->down = p;
	l->len ++;
}

void PrintCrossList(CrossLink *l)
{
	int i, j;	
	pNode p;
	for(i = 0; i < l->m; i++)
	{
		if(l->row_head[i] == NULL)
			printf("---------------------------------\n");
		else
		{
			PrintRow(l, i);
		}	
	}
	printf("\n");
}

void PrintRow(CrossLink *l, int row)
{
	int i;
	pNode p;
	for(p = l->row_head[row]->right, i = 0; p && i <= l->n; i++)
	{
		if(p->col == i)
		{
			printf("|%s\t", p->name);
			p = p->right;
		}else
			printf("|\t");
	}
	for(; i <= l->n; i++)
		printf("|\t");
	printf("\n");
}

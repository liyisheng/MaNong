#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 10000
/*
   约瑟夫环（约瑟夫问题）是一个数学的应用问题：已知n个人（以编号1，2，3...n分别表示）围坐在一张圆桌周围。从编号为k的人开始报数，数到m的那个人出列；他的下一个人又从1开始报数，数到m的那个人又出列；依此规律重复下去，直到圆桌周围的人全部出列。通常解决这类问题时我们把编号从0~n-1，最后结果+1即为原问题的解。
*/
typedef struct  tag
{
	int num;
	struct tag *next;
}Node, *pNode, *pList;
int joseph(int n, int k, int m);
int main()
{
    int a = joseph(10,1,5);
	printf("%d", a);
    return 0;
}
int joseph(int n, int k, int m)
{
	int i, count = 0;
	pNode p, q;
	pList s = NULL, r = NULL;//r尾指针
	for(i = 1; i <= n; i++)
	{
		p = (pNode)malloc(sizeof(Node));
		p->num = i;
		if(s == NULL)
			s = p, r = p, r->next = s;
		else
			p->next = r->next, r->next = p, r = p;
	}	
	p = s;
	for(i = 1; i < k; i++)
		p = p->next;
	count = 1;
	while(p ->next != p)
	{
		p = p->next;
		count++;
		if(count == m - 1)
		{
			q = p->next, p->next = q->next;
			printf("%d\n", q->num);
			free(q);
			count = 0;
		}
	}
	return p->num;
}

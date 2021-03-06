#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 10000

/*
   约瑟夫环（约瑟夫问题）是一个数学的应用问题：已知n个人（以编号1，2，3...n分别表示）围坐在一张圆桌周围。从编号为k的人开始报数，数到m的那个人出列；他的下一个人又从1开始报数，数到m的那个人又出列；依此规律重复下去，直到圆桌周围的人全部出列。通常解决这类问题时我们把编号从0~n-1，最后结果+1即为原问题的解。
*/
int joseph(int n, int k, int m);
int main()
{
    clock_t begin,end;
    double cost;
    begin = clock();
    printf("%d\n",joseph(10000,1,5));
    end = clock();
    //除以CPU执行周期
    cost = (double)(end - begin)/CLOCKS_PER_SEC;
    printf("用时%.12lf秒\n",cost);
    return 0;
}


int joseph(int n, int k, int m)
{
    int a[N] = {0};
    int i;
    int length = n;
    int flag;
    for(i = 0; i < n; i++)
	a[i] = i + 1;
     
    flag = (k + m - 1)%length - 1;	
    while(length != 1)
    {
	for(i = flag ; i < length; i++)
	    a[i] = a[i + 1];
	length--;
	flag = (flag + m - 1)%length;
    }
    return a[0];
}


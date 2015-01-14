#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 13
#define NUM 10 

void array_show(int *a, int len);
void array_init(int *a,int len);
void array_merge(int *a[], int num, int size[], int merge[]);//num:整型数组个数  size:各数组大小
void quick_sort(int s[], int low, int high);
/*
   无序数组合并成有序数组
*/
int main()
{
    clock_t begin,end;
    double cost;

    int size[NUM];
    int i,j,*merge,*a[NUM],total_num = 0;
    //生成各数组大小 //计算元素总个数
    for(i = 0; i < NUM; i++)
    {
	size[i] = rand()%100;	
	total_num += size[i];
    }
    //给各数组赋值
    for(i = 0; i < NUM; i++)
    {
	a[i] = (int *)malloc(size[i] * sizeof(int));
	array_init(a[i], size[i]);
    }
    //合并后的数组
    merge = (int *)malloc(total_num * sizeof(int));

    begin = clock();
    //给各数组排序
    for(i = 0; i < NUM; i++)
	quick_sort(a[i], 0, size[i] - 1);
    array_merge(a, NUM, size, merge);   

    end = clock();
    array_show(merge, total_num);
    free(merge);
    cost = (double)(end - begin)/CLOCKS_PER_SEC; 
    printf("%f\n",cost);



    
  //生成各数组大小 //计算元素总个数
    for(i = 0; i < NUM; i++)
    {
	size[i] = rand()%100;	
	total_num += size[i];
    }
    //给各数组赋值
    for(i = 0; i < NUM; i++)
    {
	a[i] = (int *)malloc(size[i] * sizeof(int));
	array_init(a[i], size[i]);
    }
    //合并后的数组
    int k = 0;
    merge = (int *)malloc(total_num * sizeof(int));

    begin = clock();
    for(i = 0; i < NUM; i++) 
	for(j = 0; j < size[i]; j++)
	    merge[k++] = a[i][j];
    quick_sort(merge,0,total_num -1);
    end = clock(); 
//    array_show(merge, total_num);
    free(merge);
    cost = (double)(end - begin)/CLOCKS_PER_SEC; 
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

void array_merge(int *a[], int num, int size[], int merge[])//num:整型数组个数  size:各数组大小
{                
    int i,j,k,max,count,total_num = 0; 
    for(i = 0; i < num; i++)//根据各数组个数求出 合并后的总大小
    {
	total_num += size[i];
    }
    int *temp = (int *)malloc(total_num * sizeof(int)); //临时数组 
    max = size[0];
    for(i = 0; i < max; i++)  //将第一个数组的值 拷贝到merge
    {
	merge[i] = a[0][i];
    }
    for(i = 1; i < num; i++)// 从第二个数组开始 依次插入到merge数组中(merge已经是有序的)
    {
	j = 0, k = 0, count = 0;
	while(j < size[i] && k < max)	
	{
	    if(a[i][j] <= merge[k])
	    {
		temp[count] = a[i][j];
		j++;
	    }else
	    {
		temp[count] = merge[k];
		k++;
	    }
	    count++;
	}
	if(j >= size[i])
	{
	    while(k < max)
		temp[count++] = merge[k++];
	}else
	{
	    while(j < size[i])
		temp[count++] = a[i][j++];
	}
	max = count;
	for(j = 0; j < max; j++)
	    merge[j] = temp[j];
    }
    free(temp);
}

void quick_sort(int s[], int low, int high)
{
    int privotKey = s[low];
    int l_tmp = low;
    int h_tmp = high;
    while (low < high)
    {
	while (low < high && s[high] >= privotKey)
	    high--;
	s[low] = s[high];
	while (low < high && s[low] <= privotKey)
	    low++;
	s[high] = s[low];
    }
    s[low] = privotKey;
    if (low != l_tmp)
	quick_sort(s, l_tmp, low - 1);
    if (high != h_tmp)
	quick_sort(s, high + 1, h_tmp);
}

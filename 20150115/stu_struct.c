#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 10
#define S 5
#define NUM 10

typedef struct
{
    int id;
    char name[N];
    int scores[S];
}Student, *pStu;

int sum_score(int *score, int len);
void score_init(int *score);
void name_init(char *name);
void stus_init(pStu stu_arr, int len);
void show(pStu stu);
int compare_with_score(const void *a, const void *b);

int main()
{
    pStu stus = (pStu)calloc(NUM, sizeof(Student));
    stus_init(stus, NUM);
    show(stus);
    qsort(stus, NUM, sizeof(Student), &compare_with_score);
    printf("\n");
    show(stus);

}


int compare_with_id(const void *a, const void *b)
{
    if(((Student *)a)->id > ((Student *)b)->id)
	return 1;	
    else if(((Student *)a)->id == ((Student *)b)->id )
	return 0;
    else
	return -1;
}
int compare_with_name(const void *a, const void *b)
{
   return strcmp(((Student *)a)->name, ((Student *)b)->name);
}

int compare_with_score(const void *a, const void *b)
{
    int sumScore_a = sum_score(((pStu)a)->scores, S);
    int sumScore_b = sum_score(((pStu)b)->scores, S);
    if(sumScore_a < sumScore_b)
	return -1;
    else if(sumScore_a == sumScore_b)
	return 0;
    else 
	return 1;
}
void show(pStu stu)
{
    int index; 
    int i;
    for(i = 0; i < NUM; i++)
    {
	printf("%-3d%10s", stu[i].id, stu[i].name);
	for(index = 0; index != S; index ++)
	{
	    printf("%3d ", stu[i].scores[index]);
	}
	printf("%6d", sum_score(stu[i].scores, S));
	printf("\n");
    }
}


void stus_init(pStu stu_arr, int len)
{
    int i;
    for(i = 0; i < len; i++)
    {
	stu_arr[i].id = i+1;
	name_init(stu_arr[i].name);
	score_init(stu_arr[i].scores);
    }
}
void name_init(char *name)
{
    int i;
    for(i = 0; i < N - 1; i++)
    {
	if(i == 0)				
	    name[i] = 'A' + rand()%26;
	else
	    name[i] = 'a' + rand()%26;
    }
    name[N - 1] = '\0';
}

void score_init(int *score)
{
    int i;
    for(i = 0; i < S; i++)
	score[i] = rand()%101;
}

int sum_score(int *score, int len)
{
    int i,sum = 0;
    for(i = 0; i < len; i++)
	sum += score[i];
    return sum;
}

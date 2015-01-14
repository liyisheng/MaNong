#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    int number;
    char *msg;
}unit_t;


void alloc_unit(unit_t **pp)
{
    unit_t *p = malloc(sizeof(unit_t));
    if(p == NULL)
	exit(1);

    p->number = 3;
    p->msg = malloc(20);
    strcpy(p->msg, "Hello,jo");
    *pp = p;
}

void free_unit(unit_t *p)
{
    free(p->msg);
    free(p);
}

int main()
{
    unit_t *p = NULL; 

    alloc_unit(&p);
    printf("%d\t  : %s\n",p->number, p->msg);
//    free_unit(p);
    free(p->msg);
    free(p);
    p = NULL;
    return 0;
}

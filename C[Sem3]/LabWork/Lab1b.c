#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i=5,j=10;
    int *ptr;
    int **pptr;
    ptr=&i;
    printf("%d\n",i);
    printf("%d\n",j);
    printf("%d\n",ptr);
    pptr=&ptr;
    *ptr=3;
    printf("%d\n",ptr);
    printf("%d\n",j);
    **pptr=7;
    printf("%d\n",pptr);
    ptr=&j;
    printf("%d\n",i);
    **pptr=9;
    *pptr=&i;
    *ptr=-2;
    printf("%d\n",i);
    printf("%d\n",&ptr);
    printf("%d\n",&pptr);
    printf("%d\n",ptr);
    printf("%d\n",pptr);
    printf("%d\n",j);
    return 0;
}

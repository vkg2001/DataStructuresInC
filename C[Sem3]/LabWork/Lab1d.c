#include<stdio.h>
#include<stdlib.h>
int main()
{
    float a[5];
    float *ptr;
    ptr=&(a[2]);
    *ptr=3.14;
    printf("%d\n",ptr);
    ptr+=1;
    *ptr=9.0;
    printf("%d\n",ptr);
    ptr-=3;
    *ptr=6.0;
    printf("%d\n",ptr);
    ptr+=2;
    *ptr=7.0;
    printf("%d\n",ptr);
}

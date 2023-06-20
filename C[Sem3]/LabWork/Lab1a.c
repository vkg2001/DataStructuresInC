#include<stdio.h>
#include<stdlib.h>
void calculate(int a,int b,int *sum,int *diff)
{
    *sum=a+b;
    *diff=a-b;
}
int main()
{
    int sum,diff,res=0;
    calculate(5,7,&sum,&diff);
    printf("Sum=%d\t Difference=%d",sum,diff);
    return 0;
}

#include<stdio.h>
struct result
{
    int a,b,sum,diff;
};
struct result operation(struct result r)
{
    r.sum=r.a+r.b;
    r.diff=r.a-r.b;
    return(r);
};
int main()
{
    struct result r1,temp;
    printf("Enter the numbers:");
    scanf("%d %d",&r1.a,&r1.b);
    temp=operation(r1);
    printf("Sum= %d\tDiff= %d",temp.sum,temp.diff);
    return 0;
}

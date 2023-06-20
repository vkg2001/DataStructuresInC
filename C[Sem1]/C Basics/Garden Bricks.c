#include<stdio.h>
int brick(int);
void main()
{
    int n;
    int ans=0;
    ans=brick(n);
    printf("No of bricks required is %d",ans);
}
int brick(int n)
{
    int i,j=97,sum=0;
    for(i=1;i<=25;i=i++)
    {
            sum+=j;
            j=j-4;
    }
    return sum;
}

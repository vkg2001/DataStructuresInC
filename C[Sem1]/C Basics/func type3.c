#include<stdio.h>
void sum(int a,int b);
void main()
{
     int a,b;
     printf("Enter two values:");
     scanf("%d%d",&a,&b);
     sum(a,b);
}
void sum(int x, int y)
{
    int ans;
    ans=x+y;
    printf("Sum=%d",ans);
}

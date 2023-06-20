#include<stdio.h>
void mul();
void avg();
void main()
{
    mul();
    avg();
}
void mul()
{
    int m,n,ans;
    printf("Enter two nos.:");
    scanf("%d%d",&m,&n);
    ans=m*n;
    printf("%d",ans);
}
void avg()
{
    int m,n,ans;
    printf("\nEnter two nos.:");
    scanf("%d%d",&m,&n);
    ans=(m+n)/2;
    printf("%d",ans);
}


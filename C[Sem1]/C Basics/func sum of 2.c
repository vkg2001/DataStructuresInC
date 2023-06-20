#include<stdio.h>
void sum();
void avg(); //function prototype
void main()//function calling
{
    sum();
    avg();//called function
}
void sum()
{
    int m,n,ans;
    printf("Enter two numbers:");
    scanf("%d%d",&m,&n);
    ans=m+n;
    printf("%d",ans);
}
void avg()
{
    int m,n,ans;
    printf("\nEnter two numbers:");
    scanf("%d%d",&m,&n);
    ans=(m+n)/2;
    printf("%d",ans);
}

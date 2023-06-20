#include<stdio.h>
void main()
{
    int n,i=1,sum=0;
    printf("Enter number:");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        sum+=i;
    }
    printf("Sum=%d",sum);
}

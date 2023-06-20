#include<stdio.h>
void main()
{
    int n,i,sum=0;
    printf("Enter number:");
    scanf("%d",&n);
    for(i=0;i<=n;i+=2)
    {
        sum+=i;
    }
    printf("Sum of Even=%d",sum);
}

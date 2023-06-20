#include<stdio.h>
void main()
{
    int n,i=1, sum=0;
    printf("Enter the last number:");
    scanf("%d",&n);
    while(i<=n)
    {
        sum=sum+i;
        i++;
    }
    printf("%d\n",sum);
}

#include<stdio.h>
void main()
{
    int n,i,pro=1;
    printf("Enter number:");
    scanf("%d",&n);
    for(i=1;i<=n;i+=2)
    {
        pro*=i;
    }
    printf("Multiplication of Odd=%d",pro);
}

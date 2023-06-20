#include<stdio.h>
void main()
{
    int n,i,pro=1;
    printf("Enter number:");
    scanf("%d",&n);
    for(i=2;i<=n;i+=2)
    {
        pro*=i;
    }
    printf("Multiplication of Even=%d",pro);
}



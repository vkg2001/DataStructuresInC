#include<stdio.h>
void main()
{
    int n,i=2;
    printf("Enter the last odd number to be printed:");
    scanf("%d",&n);
    while(i<=n)
    {
        printf("%d\n",i);
        i=i+2;
    }
}

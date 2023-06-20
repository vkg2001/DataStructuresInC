#include<stdio.h>
void main()
{
    int n,i=1;
    printf("Enter the last number to be printed:");
    scanf("%d",&n);
    while(i<=n)
    {
        printf("%d\n",i);
        i++;
    }
}

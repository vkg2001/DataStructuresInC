#include<stdio.h>
void main()
{
    int n,i;
    printf("Enter the last number to be printed:");
    scanf("%d",&n);
    i=n;
    while(i>0)
        {
        printf("%d\n",i);
        i--;
        }
}

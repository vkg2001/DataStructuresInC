#include<stdio.h>
void main()
{
    int n,i=1,k=1;
    printf("Enter the number:");
    scanf("%d",&n);
    while(i<=n)
       {
        k=n*i;
        i++;
       }
        printf("%d",k);
}

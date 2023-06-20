#include<stdio.h>
void main()
{
    int n,i=1;
    printf("Enter the number:");
    scanf("%d",&n);
    while(i<=10)
    {
        printf("%d\n",n*i);
        i++;
    }
}

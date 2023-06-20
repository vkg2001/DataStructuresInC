#include<stdio.h>
void main()
{
    int n,ld;
    printf("Enter the value of N:");
    scanf("%d",&n);
    while(n!=0)
    {
        ld=n%10;
        n=n/10;
        printf("%d",ld);
    }
}

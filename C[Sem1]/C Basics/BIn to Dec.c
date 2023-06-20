#include<stdio.h>
void main()
{
    int n,bin=0,i,dn,m;
    printf("Enter the value of N:");
    scanf("%d",&n);
    dn=n;
    i=1;
    while(n!=0)
    {
        m=(n%10)*i;
        bin=bin+m;
        i=i*2;
        n=n/10;
    }
    printf("\nThe Binary of %d is %d",dn,bin);
}

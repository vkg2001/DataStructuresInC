#include<stdio.h>
#include<math.h>
void main()
{
    int n,bin=0,i,dn,m;
    printf("Enter the value of N:");
    scanf("%d",&n);
    dn=n;
   i=1;
    while(n!=0)
    {
        m=(n%2)*i;
        bin=bin+m;
        i=i*10;
        n=n/2;
    }
    printf("\nThe Binary of %d is %d",dn,bin);
}


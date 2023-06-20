#include<stdio.h>
void main()
{
    int n,ld=0,fd=0,i,sum=0;
    printf("Enter the number:");
    scanf("%d",&n);
    ld=n%10;
    while(n>0)
    {
        fd=n%10;
        n=n/10;
    }
    sum=ld+fd;
    printf("Sum of %d & %d= %d",ld,fd,sum);
}

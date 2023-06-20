#include<stdio.h>
void main()
{
    int f1=0,f2=1,f3,n,i=2;
    printf("Enter the value of N:");
    scanf("%d",&n);
    while(i<=n)
    {
        f3=f1+f2;
        f1=f2;
        f2=f3;
        printf("%d\n",f3);
        i++;
    }
}



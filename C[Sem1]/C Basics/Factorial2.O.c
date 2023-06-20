#include<stdio.h>
void main()
{
    int n,i,f=1;
    printf("Enter the number:");
    scanf("%d",&n);
    i=n;
    while(i>0)
       {
        f=f*i;
        i--;
       }
        printf("%d",f);
}

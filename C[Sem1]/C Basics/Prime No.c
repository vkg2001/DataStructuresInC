#include<stdio.h>
void main()
{
    int n,i=2,flag=1;
    printf("Enter number:");
    scanf("%d",&n);
    while(i<=n/2)
    {
        if(n%i==0)
        {
            flag=0;
        }
        break;
        i++;
    }
        if(flag==0)
            printf("Not a Prime");
        else
            printf("Prime");
}

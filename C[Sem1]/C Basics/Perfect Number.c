#include<stdio.h>
void main()
{
    int num,i=1,sum=0;
    printf("Enter the number:");
    scanf("%d",&num);
    while(i<=num/2)
    {
        if(num%i==0)
        {
            sum=sum+i;
        }
        i++;
    }
    if(num==sum)
    {
        printf("Perfect Number");
    }
    else
    {
        printf("Not a Perfect Number");
    }
}

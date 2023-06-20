#include<stdio.h>
int main()
{
    int num,rem=0,sum=0,n;
    printf("Enter the number:");
    scanf("%d",&num);
    n=num;
    for(num;num>0;num=(num/10))
    {
        rem=num%10;
        sum+=rem;
    }
    if(n%sum==0)
    {
        printf("%d is Harshad number",n);
    }
    else
    {
        printf("%d is not Harshad number",n);
    }
    return 0;
}

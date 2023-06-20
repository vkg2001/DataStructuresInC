#include<stdio.h>
#include<math.h>
int main()
{
    int n,i,s,flag=1;
    printf("Enter the number\n");
    scanf("%d",&n);
    s=sqrt(n);
    for(i=2;i<=s;i++)
    {
        if(n%i==0)
        {
            flag=0;
        }
    }
    if(flag==1)
    {
        printf("it is a prime number\n");
    }
    else
    {
        printf("it is not a prime number\n");
    }
}

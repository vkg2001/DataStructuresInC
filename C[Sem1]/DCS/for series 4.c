#include<stdio.h>
void main()
{
int n,i;
float fact=1,sum=1;
printf("enter the value of n");
scanf("%d",&n);
printf("%.2f",sum);
for(i=2;i<=n;i++)
{
printf("+");
printf("1/%d!",i);
fact=fact*i;
sum=sum+1/fact;
}
printf("sum=%f",sum);
}

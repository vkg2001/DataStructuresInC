#include<stdio.h>
void main()
{
int n,i;
float sign=1,sum=0;
printf("enter the value of n");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
sum=sum+(i*sign);
sign=sign*(-1);
}
printf("sum=%f",sum);
}

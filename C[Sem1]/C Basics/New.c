#include<stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int spec(int);
int main()
{
int temp,n,fact,num,sum=0,i,ans;
scanf("%d",&num);
temp=num;
sum=0;
ans=spec(num);
if(ans==num)
printf("YES");
else
      printf("NO");
}
int spec(int num)
{
    int i,temp,fact,n,sum=0;
    while(temp>0)
{
n=temp%10;
fact=1;
for(i=1;i<=n;i++)
{
fact=fact*i;
sum=sum+fact;
temp=temp/10;
}}
        return sum;
}

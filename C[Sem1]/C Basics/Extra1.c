#include<stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main()
{
int temp,n,fact,num,sum=0,i;
scanf("%d",&num);
temp=num;
sum=0;
while(temp>0)
{
n=temp%10;
fact=1;
for(i=1;i<=n;i++)
fact=fact*i;
sum=sum+fact;
temp=temp/10;
}
if(sum==num)
printf("YES");
else
      printf("NO");
    return 0;
}

#include<stdio.h>
int main()
{
int m,ld,fact,num,sum=0,i;
scanf("%d",&num);
m=num;
while(num>0)
{
ld=num%10;
fact=1;
for(i=1;i<=num;i++)
fact=fact*i;
sum=sum+fact;
num=num/10;
}
if(sum==m)
{printf("YES");}
else{
      printf("NO");
}
return 0;
}

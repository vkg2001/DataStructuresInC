#include<stdio.h>
#include<math.h>
void main()
{
 int i,n,x;
float sum=1;

printf("\nEnter the value of x and n:");
scanf("%d%d",&x,&n);
printf("%.1f",sum);
for(i=1;i<=n;i++)
{

    printf("+");
printf("%d^%d",x,i);
sum=sum+pow(x,i);
}


printf("\nSum=%f",sum);
}

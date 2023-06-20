#include<stdio.h>
#include<math.h>
void main()
{
 int i,n,x,sum=1;
 printf("Enter the x:");
 scanf("%d",&x);
 printf("Enter the n:");
 scanf("%d",&n);
 for(i=1;i<=n;i++)
 {
      printf("1+ ");
     if(i<n)
     {
         printf("%d^%d+ ",x,i);
     }
     sum+=pow(x,i);
 }
 printf("Sum= %d",sum);
}

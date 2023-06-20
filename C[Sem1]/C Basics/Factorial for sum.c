#include<stdio.h>
 void main()
{
 int i,n,s=0,k=1;
 printf("Enter the number:");
 scanf("%d",&n);

 for(i=1;i<=n;i++)
 {
     printf("%d",i);
   if(i<n)
   {
     printf("!+ ");
   }
   k=k*i;
   s=s+k;

 }
 printf("!=%d",s);




}

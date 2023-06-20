#include<stdio.h>
void main()
{
 int i,n;
 float sum=1,fact=1;
 printf("Enter the number of terms(N):");
 scanf("%d",&n);
 for(i=1;i<=n;i++)
 {  printf("1/%d!",i);
     if(i<n)
        printf("+");
     fact=fact*i;
     sum+=1/fact;
 }
 printf("\n%f",sum);
 }

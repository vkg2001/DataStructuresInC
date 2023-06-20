#include <stdio.h>

void main()
     {
     int n,binary=0,i,dn,m;
     printf("Enter a number to convert : ");
     scanf("%d",&n);
     dn=n;
     i=1;
      while(n>0)
       {
        m=(n%2)*i;
        binary=binary+m;
        i=i*10;
        n=n/2;
       }
     printf("\nThe Binary of %d\n is %d\n",dn,binary);
 }

#include <stdio.h>
void main()
{
  int n,i,sum=0.0,x=1;
  printf("Enter the number of terms: ");
  scanf("%d",&n);
  for(i=1;i<=n;i++)
  {
     printf("%d",x);
      if(i<n)
      {
          printf("+ ");

      }
     sum=sum+x;
     x=(x*10)+1;
  }
  printf("\nThe Sum is : %d\n",sum);
}


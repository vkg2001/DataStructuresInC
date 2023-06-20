#include<stdio.h>
int main()
{
    int n,ld,sum=0;
    printf("Enter a number");
    scanf("%d",&n);
    while(n!=0)
    {
      ld=n%10;
      sum=sum+ld;
      n=n/10;
      printf("%d\n",ld);
    }
     printf("\n%d\n",sum);
}

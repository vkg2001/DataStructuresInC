#include<stdio.h>
int main()
{
    int n,ld;
    printf("Enter a number");
    scanf("%d",&n);
    while(n!=0)
    {
      ld=n%10;
      printf("%d\n",ld);
      n=n/10;
    }
}

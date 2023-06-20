#include<stdio.h>
int main()
{
    int n,ld,rev=0,m;
    printf("Enter a number");
    scanf("%d",&n);
    m=n;
    while(n!=0)
    {
      ld=n%10;
      rev=rev*10+ld;
      n=n/10;
    }
     printf("%d\n",rev);

     if(m==rev)
     {
     printf("palindrome");
     }
     else
     printf("not palindrome");

}

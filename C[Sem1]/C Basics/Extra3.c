
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int spec(int);
int main() {
    int n,m,sum,ans;
    scanf("%d",&n);
    m=n;
    sum=spec(n);
    if(m==sum)
    {printf("YES");}
    else
    {printf("NO");}
}
int spec(int n)
{
    int ld,fact,n,i;
    while(n!=0)
    {
        ld=n%10;
        fact=1;
        for(i=1;i<=ld;i++)
        {
            fact=fact*i;
            ans=ans+fact;
        }
        n=n/10;
    }
      return ans;
}

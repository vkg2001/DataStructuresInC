#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int special(int);
int facto(int);
int main() {
    int n,m,ans;
    scanf("%d",&n);
    m=n;
    ans=special(n);
    if(m==ans)
    {printf("YES");}
    else
    {printf("NO");}
    return 0;
}
int special(int n)
{
    int ld,ans=0,fact;
    while(n!=0)
    {
        ld=n%10;
        fact=facto(x);
        ans=ans+fact;
        n=n/10;
    }
    return ans;
}
int facto(int x)
{
    int i,n,ld;
        x=x*i;
    return x;
        }

#include<stdio.h>

int special(int n)
{
    int ans=0,m,i, fact;
    m=n;
    while(n!= 0)
    {
        fact=1;
        for(i= 1;i<=n;i++)
        {
            fact=fact*i;
        }
        ans=ans+fact;
        n=n/10;
    }
    if(m==ans)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
}
int main()
{
    int num,ans;
    scanf("%d",&num);
    ans=special(num);
    if(num==ans)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
    return 0;
}

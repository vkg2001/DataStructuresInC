#include <stdio.h>
int gcd(int,int);
int main()
{
    int n1,n2,i,ans;
    printf("Enter two integers: ");
    scanf("%d %d",&n1,&n2);
    ans=gcd(n1,n2);
    printf("Students who will get pens and pencils is %d",ans);
    return 0;
}
int gcd(int n1,int n2)
{
    int i,hcf;
    for(i=1;i<=n1&&i<=n2;++i)
    {
        if(n1%i==0&&n2%i==0)
            hcf=i;
    }
    return hcf;
}

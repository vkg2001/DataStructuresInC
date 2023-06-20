#include<stdio.h>
int jog(int);
void main()
{
    int i,ans,n;
    scanf("%d",&n);
    ans=jog(n);
    printf("Days taken: %d",ans);
}
int jog(int n)
{
    int i,l=1;
    for(i=12;i<n;l++)
    {
        i=i+6;
    }
    return l;
}

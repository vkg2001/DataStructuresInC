#include<stdio.h>
int main()
{
    int i,f1=0,f2=1,f3,m,n;
    printf("Enter a number");
    scanf("%d",&n);
    printf("%d\t%d\t",f1,f2);
    i=2;
    while(i<=n)
    {
      f3=f1+f2;
        f1=f2;
        f2=f3;
        printf("%d\t",f3);
        i++;
    }
}

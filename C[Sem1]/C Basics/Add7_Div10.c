#include<stdio.h>
int enc(int n)
{
    int a,b,c,d;
    a=n/1000;
    b=(n%1000)/100;
    c=(n%100)/10;
    d=n%10;
    a=(a+7)%10;
    b=(b+7)%10;
    c=(c+7)%10;
    d=(d+7)%10;
    return (c*1000+d*100+a*10+b);
}
int dec(int n)
{
    int a,b,c,d;
    a=n/1000;
    b=(n%1000)/100;
    c=(n%100)/10;
    d=n%10;
    a=(a+3)%10;
    b=(b+3)%10;
    c=(c+3)%10;
    d=(d+3)%10;
    return(c*1000+d*100+a*10+b);
}
int main()
{
    int n,num;
    printf("Enter the number:");
    scanf("%d",&n);
    num=enc(n);
    printf("%d",num);
    printf("\n%d",dec(num));
}

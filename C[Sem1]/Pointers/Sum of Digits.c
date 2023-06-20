#include<stdio.h>
void sumdigit(int n,int *s);
void main()
{
    int num,sum=0;
    scanf("%d",&num);
    sumdigit(num,&sum);
    printf("SUM OF DIGITS: %d",sum);
}
void sumdigit(int n,int *s)
{
    int ld;
    while(n!=0)
    {
        ld=n%10;
        *s+=ld;
        n=n/10;
    }
}

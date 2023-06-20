#include<stdio.h>
void simulate(int n1,int n2,int *s,int *d,int *p,int *q);
void main()
{
    int n1,n2,s=0,d=0,p=0,q=0;
    printf("Enter the two numbers: \n");
    scanf("%d%d",&n1,&n2);
    simulate(n1,n2,&s,&d,&p,&q);
    printf("Sum: %d\nDifference: %d\nProduct: %d\nQuotient: %d",s,d,p,q);
}
void simulate(int num1,int num2,int *s1,int *d1,int *p1,int *q1)
{
    *s1=num1+num2;
    *d1=num1-num2;
    *p1=num1*num2;
    *q1=num1/num2;
}

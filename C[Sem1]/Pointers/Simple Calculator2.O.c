#include<stdio.h>
void cal(float a,float b,float *sum,float *diff,float *pro,float *div);
void main()
{
    float a,b,s,d,p,q;
    printf("Enter a and b\n");
    scanf("%f%f",&a,&b);
    cal(a,b,&s,&d,&p,&q);
    printf("\n sum of two numbers=%f\n",s);
    printf("\n difference of two numbers=%f\n",d);
    printf("\n product of two numbers=%f\n",p);
    printf("\n quotient of two numbers=%f\n",q);
}
void cal(float a,float b,float *sum,float *diff,float *pro,float *div)
{
    *sum=a+b;
    *diff=a-b;
    *pro=a*b;
    *div=a/b;
}


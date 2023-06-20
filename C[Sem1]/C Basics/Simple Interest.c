#include<stdio.h>
#include<math.h>
void main()
{
    float p,t,r,n;
    float si, ci;
    printf("Enter Principal Amount, Time, Rate, number:");
    scanf("%f%f%f%f",&p,&t,&r,&n);
    si=(p*t*r)/100;
    ci=p*pow((1+(r/n)),(n*t));
    printf("Simple Interest:%f", si);
    printf("Compound Interest:%f", ci);
}

#include<stdio.h>
void main()
{
    float s,tax;
    printf("Enter the Salary:");
    scanf("%f",&s);
    if(s>200000&&s<=500000)
        tax=(s-200000)*.1;
    else if(s>500000&&s<=800000)
        tax=(s-500000)*.2+30000;
    else if(s>800000&&s<=1000000)
        tax=(s-800000)*.2+90000;
    else if(s>1000000)
        tax=(s-1000000)*.4+180000+.02*(s-100000);
    else printf("No Tax!");
    printf("Tax=%f",tax);
}

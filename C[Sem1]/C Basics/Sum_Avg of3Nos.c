#include<stdio.h>
void main()
{
    int a, b ,c;
    float sum, avg;
    printf("Enter 3 numbers:");
    scanf("%d%d%d", &a, &b, &c);
    sum=a+b+c;
    avg=sum/3;
    printf("Sum=%f", sum);
    printf("Average=%f", avg);
}

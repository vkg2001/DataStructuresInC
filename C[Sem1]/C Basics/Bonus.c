#include<stdio.h>
void main()
{
    int e;
    float b, bs, ts;
    printf("Enter experience and basic salary:");
    scanf("%d%f",&e,&bs);
    if(e>=5&&e<=7)
        {b=0.1*bs;
        printf("Bonus=%f", b);}
    else if(e>=8&&e<=10)
        {b=0.2*bs;
        printf("Bonus=%f", b);}
    else if(e>10)
        {b=0.3*bs;
        printf("Bonus=%f", b);}
    else
        {printf("No Bonus");}
    ts=b+bs;
    printf("\tTotal Salary=%f", ts);
}

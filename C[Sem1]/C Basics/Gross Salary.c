#include<stdio.h>
void main()
{
    float bs, da, ha, gs;
    printf("Enter Basic Salary:");
    scanf("%f",&bs);
    da=0.4*bs;
    ha=0.2*bs;
    gs=bs+da+ha;
    printf("Gross Salary:%f", gs);
}

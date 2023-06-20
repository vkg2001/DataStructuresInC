#include<stdio.h>
void main()
{
    int m;
    printf("Enter amount:");
    scanf("%d",&m);
    if(m>=1000&&m<10000)
        {
        printf("Goa");}
    else if(m>=10000&&m<20000)
        {
        printf("Bombay");}
    else if(m>=20000)
        {
        printf("Mars");}
    else
        {printf("BVB");}
}

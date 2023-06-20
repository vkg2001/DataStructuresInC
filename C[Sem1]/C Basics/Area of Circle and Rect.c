#include<stdio.h>
void main()
{
    int r,a,b;
    float ac, ar;
    printf("Enter radius of circle:");
    scanf("%d",&r);
    printf("Enter sides of rectangle:");
    scanf("%d%d",&a,&b);
    ac=3.14*r*r;
    ar=a*b;
    printf("Area of circle:%f", ac);
    printf("Area of rectangle:%f", ar);
}

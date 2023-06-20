#include<stdio.h>
void main()
{
    int r;
    float vol,sa;
    printf("Enter radius of sphere:");
    scanf("%d",&r);
    vol=((4/3)*3.14*r*r);
    sa=(4*3.14*r*r);
    printf("Volume of Sphere:%f", vol);
    printf("Surface Area of Sphere:%f", sa);
}

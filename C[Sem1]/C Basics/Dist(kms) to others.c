#include<stdio.h>
void main()
{
    int a;
    float mtr,ft,cm,in;
    printf("Enter distance in kms:");
    scanf("%d",&a);
    mtr=a*1000;
    ft=mtr*3.2808;
    cm=mtr*100;
    in=cm*0.3937;
    printf("Distance in meters:%f", mtr);
    printf("Distance in feets:%f", ft);
    printf("Distance in centimeters:%f", cm);
    printf("Distance in inches:%f", in);
}

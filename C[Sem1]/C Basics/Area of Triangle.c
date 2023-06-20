#include<stdio.h>
#include<math.h>
void main()
{
  float a,b,c;
  float s,area;
    printf("Enter the 3 sides of triangle:");
    scanf("%f%f%f", &a, &b, &c);
    s=(a+b+c)/2;
    area=sqrt(s*(s-a)*(s-b)*(s-c));
    printf("Area of Triangle=%f", area);
}

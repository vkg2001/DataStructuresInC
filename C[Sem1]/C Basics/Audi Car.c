#include<stdio.h>
void main()
{
    float pp, m, ta, dist;
    printf("Enter the Petrol Price, Mileage, Total Amount:");
    scanf("%f%f%f", &pp,&m, &ta);
    dist=(ta/pp)*m;
    printf("Total Distance traveled:%f", dist);
}

#include<stdio.h>
void main()
{
    float a, charge;
    char type;
    printf("Enter the type and area:");
    scanf("%c%f",&type,&a);
    if(type=='r')
    {
        if(a<=1000)
            charge=10;
        else if(a>1000&&a<=3000)
            charge=30;
        else if(a>3000)
            charge=50;
    }
    else if(type=='c')
    {
       if(a<=1000)
            charge=50;
        else if(a>1000&&a<=3000)
            charge=100;
        else if(a>3000)
            charge=200;
    }
    else if(type=='o')
    {
       if(a<=1000)
            charge=300;
        else if(a>1000&&a<=3000)
            charge=500;
        else if(a>3000)
            charge=600;
    }
    printf("The charge of Dump:%f", charge);
}

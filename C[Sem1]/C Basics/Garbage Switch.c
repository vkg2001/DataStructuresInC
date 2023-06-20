#include<stdio.h>
void main()
{
    float a, charge;
    char type;
    printf("Enter the type and area:");
    scanf("%c%f",&type,&a);
    switch(type)
    {
        case 'R': case 'r':
        if(a<=1000)
            charge=10;
        else if(a>1000&&a<=3000)
            charge=30;
        else if(a>3000)
            charge=50;
        printf("Charge=%f",charge);
        break;
        case 'C': case 'c':
       if(a<=1000)
            charge=50;
        else if(a>1000&&a<=5000)
            charge=100;
        else if(a>5000)
            charge=200;
        printf("Charge=%f",charge);
            break;
        case 'O': case 'o':
       if(a<=10000)
            charge=300;
        else if(a>10000&&a<=50000)
            charge=500;
        else if(a>50000)
            charge=600;
        printf("Charge=%f",charge);
        break;
        default: printf("Invalid type");
    }
}

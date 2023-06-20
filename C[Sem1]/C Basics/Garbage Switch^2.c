#include<stdio.h>
void main()
{
    int a, charge;
    char type;
    printf("Enter the type and area:");
    scanf("%c%d",&type,&a);
    switch(type)
    {
        case 'R': case 'r': switch(a)
        {
            case 0 ... 1000:
            charge=10;
            break;
            case 1001 ... 3000:
            charge=30;
            break;
            case 3001 ... 10000:
            charge=50;
            break;
        printf("Charge=%d",charge);
        break;
        }
        case 'C': case 'c': switch(a)
        {
            case 0 ... 1000:
            charge=50;
            break;
            case 1001 ... 5000:
            charge=100;
            break;
            case 5001 ... 10000:
            charge=200;
            break;
        printf("Charge=%d",charge);
        break;
        }
        case 'O': case 'o': switch(a)
       {
            case 0 ... 10000:
            charge=300;
            break;
            case 10001 ... 50000:
            charge=500;
            break;
            case 50001 ... 100000:
            charge=600;
            break;
        printf("Charge=%d",charge);
        break;
        }
        default: printf("Invalid type");
    }
}


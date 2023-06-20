#include<stdio.h>
void main()
{
    int d,charge,bill;
    char type;
    printf("Enter the type of ROOM:");
    scanf("%c",&type);
    switch(type)
    {
        case 'I': case 'i': printf("Enter the number of days:");
                            scanf("%d",&d);
                            if(d>0&&d<=5)
                            {charge=5000;
                            bill=d*charge;}
                            else if(d>=6&&d<=10)
                            {charge=8000;
                            bill=5*5000+(d-5)*8000;}
                            else if(d>10)
                            {charge=10000;
                            bill=5*5000+5*8000+(d-10)*10000;}
                            printf("The charge per day and total bill is %d\t%d",charge,bill);
                            break;
        case 'G': case 'g': printf("Enter the number of days:");
                            scanf("%d",&d);
                            if(d>0&&d<=5)
                            {charge=2000;
                            bill=d*charge;}
                            else if(d>=6&&d<=10)
                            {charge=4000;
                            bill=5*2000+(d-5)*4000;}
                            else if(d>10)
                            {charge=6000;
                            bill=5*2000+5*4000+(d-10)*6000;}
                            printf("The charge per day and total bill is %d\t%d",charge,bill);
                            break;
        case 'S': case 's': printf("Enter the number of days:");
                            scanf("%d",&d);
                            if(d>0&&d<=5)
                            {charge=3000;
                            bill=d*charge;}
                            else if(d>=6&&d<=10)
                            {charge=6000;
                            bill=5*3000+(d-5)*6000;}
                            else if(d>10)
                            {charge=8000;
                            bill=5*3000+5*6000+(d-10)*8000;}
                            printf("The charge per day and total bill is %d\t%d",charge,bill);
                            break;
        default: printf("Invalid Choice!");
}
}

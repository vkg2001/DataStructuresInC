#include<stdio.h>
void main()
{
    char item;
    int price,n;
    printf("Enter the item and quantity: ");
    scanf("%c%d",&item,&n);
    switch(item)
    {
        case 'B': case 'b': price=n*250;
                            printf("Burger: %d",price);
                            break;
        case 'C': case 'c': price=n*200;
                            printf("Cake: %d",price);
                            break;
        case 'P': case 'p': price=n*750;
                            printf("Pizza: %d",price);
                            break;
        case 'S': case 's': price=n*150;
                            printf("Sandwich: %d",price);
                            break;
        default: printf("No Item! Stay Hungry!");
    }
}

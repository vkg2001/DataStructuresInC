#include<stdio.h>
#include<math.h>
void main()
{
    int r,a,b,c,choice;
    float s, area;
    printf(" 1.RECTANGLE\n 2.SQUARE\n 3.TRIANGLE\n 4.CIRLCE\n ENTER THE CHOICE:");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: printf("ENTER THE SIDES OF RECTANGLE:");
                printf("\nENTER THE LENGTH:");
                scanf("%d",&a);
                printf("ENTER THE BREADTH:");
                scanf("%d",&b);
                area=a*b;
                printf("AREA OF RECTANGLE:%f",area);
                break;
        case 2: printf("ENTER THE SIDE OF SQUARE:");
                scanf("%d",&a);
                area=a*a;
                printf("AREA OF SQUARE:%f",area);
                break;
        case 3: printf("ENTER THE SIDES OF TRIANGLE:");
                printf("ENTER THE 3 SIDES:");
                scanf("%d%d%d",&a,&b,&c);
                s=(a+b+c)/2;
                area=sqrt(s*(s-a)*(s-b)*(s-c));
                printf("AREA OF TRIANGLE:%f",area);
                break;
        case 4: printf("ENTER THE RADIUS OF CIRLCE:");
                scanf("%d",&r);
                area=3.14*r*r;
                printf("AREA OF CIRLCE:%f",area);
                break;
        default: printf("INVALID CHOICE!");
    }
}

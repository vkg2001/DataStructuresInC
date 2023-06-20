#include<stdio.h>
void main()
{
    int a,b,x,choice;
    scanf("%d%d",&a,&b);
    printf("Enter 1-ADD, 2-SUB, 3-MUL, 4-DIV: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:x=a+b;
                printf("Sum:%d",x);
                break;
        case 2:if(a>b)
                x=a-b;
                else if(b>a)
                x=b-a;
                printf("Difference:%d",x);
                break;
        case 3:x=a*b;
                printf("Product:%d",x);
                break;
        case 4:x=a/b;
                printf("Division:%d",x);
                break;
        default: printf("Invalid!");
    }
}

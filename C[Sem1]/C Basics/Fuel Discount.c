#include<stdio.h>
void main()
{
    char cat;
    int l,bill,cost;
    printf("Enter the category:");
    scanf("%c",&cat);
    switch(cat)
    {
        case 'P': case 'p': printf("Enter the Volume:");
                            scanf("%d",&l);
                            cost=95*l;
                            if (l>0&&l<20)
                                printf("No Discount");
                            else if(l>=20&&l<=40)
                                bill=cost-.05*cost;
                            else if(l>40&&l<=60)
                                bill=cost-.1*cost;
                            else if(l>60)
                                printf("MAX Capacity reached");
                            printf("Bill=%d",bill);
                            break;
        case 'D': case 'd': printf("Enter the Volume:");
                            scanf("%d",&l);
                            cost=85*l;
                            if (l>0&&l<20)
                                printf("No Discount");
                            else if(l>=20&&l<=40)
                                bill=cost-.07*cost;
                            else if(l>40&&l<=60)
                                bill=cost-.11*cost;
                            else if(l>60)
                                printf("MAX Capacity reached");
                            printf("Bill=%d",bill);
                            break;
        case 'C': case 'c': printf("Enter the Volume:");
                            scanf("%d",&l);
                            cost=44*l;
                            if (l>0&&l<20)
                                printf("No Discount");
                            else if(l>=20&&l<=40)
                                bill=cost-.06*cost;
                            else if(l>40&&l<=60)
                                bill=cost-.09*cost;
                            else if(l>60)
                                printf("MAX Capacity reached");
                            printf("Bill=%d",bill);
                            break;
        default: printf("Invalid Choice");
    }
}

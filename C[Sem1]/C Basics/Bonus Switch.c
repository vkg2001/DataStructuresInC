#include<stdio.h>
void main()
{
    int cat,exp;
    float bs,ns;
    printf("Enter the category, experience and Basic Salary:");
    scanf("%d%d%f",&cat,&exp,&bs);
    switch(cat)
    {
        case 1: if(exp>=5&&exp<=7)
                ns=bs=.1*bs;
                else if(exp>=8&&exp<10)
                ns=bs+.2*bs;
                else if(exp>10)
                ns=bs+.3*bs;
                else printf("NO BONUS");
                printf("Net Salary:%f",ns);
                break;
        case 2: if(exp>=5&&exp<=7)
                ns=bs=.3*bs;
                else if(exp>=8&&exp<10)
                ns=bs+.4*bs;
                else if(exp>10)
                ns=bs+.5*bs;
                else printf("NO BONUS");
                printf("Net Salary:%f",ns);
                break;
        default: printf("Invalid Choice");
    }
}



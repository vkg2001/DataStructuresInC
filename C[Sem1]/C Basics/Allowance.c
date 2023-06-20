#include<stdio.h>
void main()
{
    int type;
    float bs,gs,ns,tax;
    printf("Enter the tier:");
    scanf("%d",&type);
    printf("Enter the Basic Salary:");
    scanf("%f",&bs);
    if(type==1)
    {
        gs=bs+.25*bs+1500;
        if(gs<=2000)
            ns=gs;
        else if(gs>2000&&gs<=4000)
            ns=gs-0.03*gs;
        else if(gs>4000&&gs<=5000)
            ns=gs-0.05*gs;
        else if(gs>5000)
            ns=gs-0.08*gs;
    }
    else if(type==2)
    {
        gs=bs+.25*bs+950;
        if(gs<=2000)
            gs=ns;
        else if(gs>2000&&gs<=4000)
            ns=gs-0.03*gs;
        else if(gs>4000&&gs<=5000)
            ns=gs-0.05*gs;
        else if(gs>5000)
            ns=gs-0.08*gs;
    }
    else if(type==3)
    {
        gs=bs+.25*bs+600;
        if(gs<=2000)
            gs=ns;
        else if(gs>2000&&gs<=4000)
            ns=gs-0.03*gs;
        else if(gs>4000&&gs<=5000)
            ns=gs-0.05*gs;
        else if(gs>5000)
            ns=gs-0.08*gs;
    }
    else if(type==4)
    {
        gs=bs+.25*bs+250;
        if(gs<=2000)
            gs=ns;
        else if(gs>2000&&gs<=4000)
            ns=gs-0.03*gs;
        else if(gs>4000&&gs<=5000)
            ns=gs-0.05*gs;
        else if(gs>5000)
            ns=gs-0.08*gs;
    }
    printf("Net Salary:%f",ns);
}

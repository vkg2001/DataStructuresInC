#include<stdio.h>
void main()
{
int it,ot;
float tt,charge;
char type;
printf("Enter the type:");
scanf("%c",&type);
printf("\tEnter IN time:");
scanf("%d",&it);
printf("\tEnter OUT time:");
scanf("%d",&ot);
tt=ot-it;
if(type=='f')
{
    if(tt<=8)
        charge=tt*20;
    else if(tt>8)
        charge=20*8+(tt-8)*30;
        printf("No. of hours vehicle parked:%f\tTotal Charge:%f",tt,charge);
}
else if(type=='t')
{
    if(tt<=8)
        charge=tt*10;
    else if(tt>8)
        charge=10*8+(tt-8)*20;
        printf("No. of hours vehicle parked:%f\tTotal Charge:%f",tt,charge);
}
}

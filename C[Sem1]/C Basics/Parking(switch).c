#include<stdio.h>
void main()
{
    int at,dt,tt,amt;
    char type;
    printf("Enter Type,Arrival & Departure times: ");
    scanf("%c%d%d",&type,&at,&dt);
    tt=dt-at;
    switch(type)
    {
        case 'F':
        case 'f':if(tt<=8)
                    amt=tt*20;
                else if(tt>8)
                    amt=8*20+(tt-8)*30;
                printf("Total Amount:%d",amt);
                break;
        case 'T':
        case 't':if(tt<=8)
                    amt=tt*10;
                else if(tt>8)
                    amt=8*10+(tt-8)*20;
                printf("Total Amount:%d",amt);
                break;
    }
}

#include<stdio.h>
#include<string.h>
typedef struct recharge
{
    char rname[20];
}R;
typedef struct hotel
{
    char hname[20];
    float ha;
}H;
typedef struct phonetm
{
    char tname[20];
    float ta;
    int d;
    R rech;
    H hot;
}PTM;
void read(PTM[],int);
void compute(PTM[],int);
void high(PTM[],int);
void main()
{
    PTM t[100];
    int n;
    printf("ENTER THE NUMBER OF TRANSACTIONS:\t");
    scanf("%d",&n);
    read(t,n);
    compute(t,n);
    high(t,n);
}
void read(PTM t[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("TRANSACTION NAME\tAMOUNT\tDAYS\n");
        scanf("%s %f %d",t[i].tname,&t[i].ta,&t[i].d);
    }
}
void compute(PTM t[],int n)
{
    int temp,i;
    float rsum=0, hsum=0;;
    char r[]="RECHARGE";
    for(i=0;i<n;i++)
    {
        temp=strcmp(t[i].tname,r);
        if(temp==0)
        {
            rsum+=t[i].ta;
        }
        else
        {
            hsum+=t[i].ta;
        }
    }
    printf("\nTOTAL RECHARGE TRANSACTIONS SUM:\t %0.2f",rsum);
    printf("\nTOTAL HOTEL BOOKING SUM:\t %0.2f",hsum);
}
void high(PTM t[],int n)
{
    int i;
    float highest;
    highest=t[0].ta;
    for(i=1;i<n;i++)
    {
        if(t[i].ta>highest)
        {
            highest=t[i].ta;
        }
    }
    printf("\nHIGHEST TRANSACTION IS:\t\t %0.2f",highest);
}

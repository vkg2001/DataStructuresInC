#include<stdio.h>
#include<string.h>
typedef struct hotel
{
    float amt;
}HT;
typedef struct recharge
{
    char trans[20];
    float amt;
    HT hoteltrans;
}TR;
void read(TR[],int);
void display(TR[],int);
void rech(TR[],int);
void high(TR[],int);
void main()
{
    TR t[100];
    int n;
    printf("ENTER THE NUMBER OF TRANSACTIONS:\t");
    scanf("%d",&n);
    read(t,n);
    rech(t,n);
    high(t,n);
}
void read(TR t[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("TRANSACTION NAME\tAMOUNT\t\n");
        scanf("%s %f",t[i].trans,&t[i].amt);
    }
}
void high(TR t[],int n)
{
    int i;
    float highest;
    highest=t[0].amt;
    for(i=1;i<n;i++)
    {
        if(t[i].amt>highest)
        {
            highest=t[i].amt;
        }
    }
    printf("\nHIGHEST TRANSACTION IS:\t\t %0.2f",highest);
}
void rech(TR t[],int n)
{
    int temp,i;
    float sum;
    char s[]="RECHARGE";
    for(i=0;i<n;i++)
    {
        temp=strcmp(t[i].trans,s);
        if(temp==0)
        {
            sum+=t[i].amt;
        }
    }
    printf("\nTOTAL RECHARGE TRANSACTIONS SUM:\t %0.2f",sum);
}

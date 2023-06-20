#include<stdio.h>
typedef struct recharge
{
    char name[20];
    char type[20];
    float ra;
}R;
typedef struct hotel
{
    char name[20];
    char location[20];
    int d;
    float ha;
}H;
typedef struct PhoneTM
{
    R rec;
    H hot;
}PTM;
void read(PTM x[20], int n)
{
    int i;
    for (i=0;i<n;i++)
    {
    printf("\nENTER THE AMOUNT SPENT ON %d RECHARGE: 1.NAME\t2.MOBILE\t3.COST\nHOTEL BOOKING:1.NAME\t2.LOCATION\t3.DAYS\t4.COST\n", i+1);
    scanf("%s%s%f%s%s%d%f", x[i].rec.name, x[i].rec.type, &x[i].rec.ra, x[i].hot.name, x[i].hot.location, &x[i].hot.d, &x[i].hot.ha);
    }
}
void display(PTM x[20], int n)
{
    int i;
    for (i=0;i<n;i++)
    {
       printf("\n%d. RECHARGE\n",i+1);
       printf("NAME\tMOBILE\tCOST\n");
       printf("%s\t\t%s\t\t%0.2f\n", x[i].rec.name, x[i].rec.type, x[i].rec.ra);
    }
    for (i=0;i<n;i++)
    {
        printf("\n%d. HOTEL BOOKING\n");
        printf("NAME\t\LOCATION\t\tDAYS\t\tCOST\n");
        printf("%s\t%s\t%d\t%0.2f\n", x[i].hot.name, x[i].hot.location, x[i].hot.d, x[i].hot.ha);
    }
}
void total(PTM x[20], int n)
{
    int i;
    float s=0;
    for(i=0;i<n;i++)
    {
        s=s+x[i].rec.ra;
    }
    printf("\nTOTAL SPENT ON RECHARGE:%0.2f", s);
}
void highest_transaction(PTM x[100], int n)
{
    int i,j,k,s=0,t=0,u=0;
    float d=0,b=0,c=0;
    for (i=0;i<n;i++)
    {
        if(x[i].rech.money>b)
        {
            b=x[i].rech.money;
            s=i;
        }
    }
    for(j=0;j<n;j++)
    {
        if(x[j].hotel.cost>c)
        {
            c=x[j].hotel.cost;
            t=j;
        }
    }

    if(b>=c&&b>=d)
    {
        printf("\nHighest transaction is for %d recharge\n",s);
        printf("Mobile\t\tTelephone\n");
        printf("%s\t\t%s\t\t%0.2f\n", x[s].rech.name, x[s].rech.type, x[s].rech.money);
    }
    else if(c>=b&&c>=d)
    {
        printf("\nHighest transaction is for %d hotel booking\n",t);
        printf("Name\t\tLocation\t\tDays\t\tCost\n");
        printf("%s\t%s\t%d\t%0.2f\n", x[t].hotel.name, x[t].hotel.location, x[t].hotel.days, x[t].hotel.cost);
    }


}
void main()
{
    int n;
    PTM a[100];
    printf("Enter the number of transactions:");
    scanf("%d", &n);
    read(a,n);
    display(a,n);
    total_recharge(a,n);
    highest_transaction(a,n);
}

#include<stdio.h>
typedef struct recharge
{
    char name[20];
    char type[20];
    float money;
}RE;
typedef struct hotelbooking
{
    char name[20];
    char location[20];
    int days;
    float cost;
}HB;
typedef struct PhoneTM
{
    RE rech;
    HB hotel;
}PTM;
void read(PTM a[20], int n);
void display(PTM a[20], int n);
void total(PTM a[20], int n);
void highest(PTM a[20], int n);
void main()
{
    int n;
    PTM a[20];
    printf("ENTER NUMBER OF TRANSACTIONS:");
    scanf("%d", &n);
    read(a,n);
    display(a,n);
    total(a,n);
    highest(a,n);
}
void read(PTM a[20], int n)
{
    int i;
    for (i=0;i<n;i++)
    {
    printf("\nENTER MONEY SPENT ON %d RECHARGE: 1.NAME\t2.TYPE\t3.COST\nHOTEL BOOKING:1.NAME\t2.LOCATION\t3.DAYS\t4.COST\n", i+1);
    scanf("%s%s%f%s%s%d%f", a[i].rech.name, a[i].rech.type, &a[i].rech.money, a[i].hotel.name, a[i].hotel.location, &a[i].hotel.days, &a[i].hotel.cost);
    }
}
void display(PTM a[20], int n)
{
    int i;
    for (i=0;i<n;i++)
    {
       printf("\n%d.RECHARGE\n",i+1);
       printf("NAME\tTYPE\tCOST\n");
       printf("%s\t%s\t%0.2f\n", a[i].rech.name, a[i].rech.type, a[i].rech.money);
    }
    for (i=0;i<n;i++)
    {
        printf("\n%d.HOTEL BOOKING\n",i+1);
        printf("NAME\t\tLOCATION\t\tDAYS\t\tCOST\n");
        printf("%s\t\t%s\t\t%d\t\t%0.2f\n", a[i].hotel.name, a[i].hotel.location, a[i].hotel.days, a[i].hotel.cost);
    }
}
void total(PTM a[20], int n)
{
    int i;
    float rs=0,hs=0;
    for(i=0;i<n;i++)
    {
        rs=rs+a[i].rech.money;
    }
    printf("\nTOTAL AMOUNT SPENT ON RECHARGE:%0.2f", rs);
    printf("\n\n");
    for(i=0;i<n;i++)
    {
        hs=hs+a[i].hotel.cost;
    }
    printf("\nTOTAL AMOUNT SPENT ON HOTEL BOOKING:%0.2f", hs);
    printf("\n\n");
}
void highest(PTM a[20], int n)
{
    int i,j,k,s=0,t=0,u=0;
    float d=0,b=0,c=0;
    for (i=0;i<n;i++)
    {
        if(a[i].rech.money>b)
        {
            b=a[i].rech.money;
            s=i;
        }
    }
    for(j=0;j<n;j++)
    {
        if(a[j].hotel.cost>c)
        {
            c=a[j].hotel.cost;
            t=j;
        }
    }
    if(b>=c&&b>=d)
    {
        printf("\nHIGHEST TRANSACTION IS FOR %d RECHARGE\n",s);
        printf("TYPE\t\tAMOUNT\n");
        printf("%s\t\t%s\t\t%0.2f\n", a[s].rech.name, a[s].rech.type, a[s].rech.money);
    }
    else if(c>=b&&c>=d)
    {
        printf("\nHIGHEST TRANSACTION IS FOR %d HOTEL BOOKING\n",t);
        printf("NAME\t\tLOCATION\t\tDAYS\t\tCOST\n");
        printf("%s\t%s\t%d\t%0.2f\n", a[t].hotel.name, a[t].hotel.location, a[t].hotel.days, a[t].hotel.cost);
    }
}

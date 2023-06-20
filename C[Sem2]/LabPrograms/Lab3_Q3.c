#include <stdio.h>
#include <stdlib.h>
typedef struct mytrip
{
    char cname[20],dest[10];
    int tno,price,days;
    int dis;
}MMT;

void read(MMT *m,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("ENTER TXN NO., CUSTOMER NAME, DESTINATION, PRICE, DAYS OF CUSTOMER %d :\n",i+1);
        scanf("%d%s%s%d%d",&m[i].tno,m[i].cname,m[i].dest,&m[i].price,&m[i].days);
    }
}
void print(MMT *m,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("\nTXN NO.\tCUSTOMER NAME\tDESTINATION\tPRICE\tDAYs\n");
        printf("%d\t%s\t\t%s\t%d\t%d",m[i].tno,m[i].cname,m[i].dest,m[i].price,m[i].days);
    }
}
void discount(MMT *m,int n)
{
    int dis,total=0;
    for(int i=0;i<n;i++)
    {
        if(m[i].tno%25==0)
        {
            m[i].dis=0.5*m[i].price;
            printf("\nCUSTOMER %d WILL GET DISCOUNT OF: %d",i+1,m[i].dis);
        }
        else
        {
            m[i].dis=0.0;
            printf("\nCUSTOMER %d WILL GET DISCOUNT OF: %d",i+1,m[i].dis);
        }
    }
    for(int i=0;i<n;i++)
    {
        total+=(m[i].dis);
    }
    printf("\nTOTAL DISCOUNT: %d", total);
}
int main()
{
    int n;
    MMT *m;
    printf("ENTER NUMBER OF CUSTOMERS:\n");
    scanf("%d",&n);
    m=calloc(n,sizeof(MMT));
    read(m,n);
    print(m,n);
    discount(m,n);
    return 0;
}

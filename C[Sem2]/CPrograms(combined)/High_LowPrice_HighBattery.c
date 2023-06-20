#include<stdio.h>
typedef struct mobile
{
    char brand[20],series[20];
    int price,pixels;
    float memory;
    int battery;
}MOB;
void read(MOB[]);
void display(MOB[]);
void display_result(MOB[],int);
void min_price(MOB[]);
void max_price(MOB[]);
void max_battery(MOB[]);
int main()
{
    MOB m1[11];
    read(m1);
    display(m1);
    min_price(m1);
    max_price(m1);
    max_battery(m1);
    return 0;
}
void read(MOB m1[11])
{
    int i;
    for(i=0;i<4;i++)
    {
        printf("Brand\tSeries\tPrice\tCamera\tMemory\tBattery\n");
        scanf("%s %s %d %d %f 4%d\n",m1[i].brand,m1[i].series,&m1[i].price,&m1[i].pixels,&m1[i].memory,&m1[i].battery);
    }
    printf("\n");
}
void display(MOB m1[11])
{
    int i;
    for(i=0;i<4;i++)
    {
        printf("Brand\tSeries\tPrice\tCamera\tMemory\tBattery\n");
        printf("%s\t%s\t%d\t%d\t%.2f\t%d\n",m1[i].brand,m1[i].series,m1[i].price,m1[i].pixels,m1[i].memory,m1[i].battery);
    }
    printf("\n");
}
void display_result(MOB m1[11],int i)
{
    printf("Brand\tSeries\tPrice\tCamera\tMemory\tBattery\n");
    printf("%s\t%s\t%d\t%d\t%.2f\t%d\n",m1[i].brand,m1[i].series,m1[i].price,m1[i].pixels,m1[i].memory,m1[i].battery);
}
void min_price(MOB m1[11])
{
    int i,min,index=0;
    min=m1[index].price;
    for(i=1;i<4;i++)
    {
        if(m1[i].price<min)
        {
            min=m1[i].price;
            index=i;
        }
    }
    printf("Mobile with lowest price:\n");
    display_result(m1,index);
    printf("\n");
}
void max_price(MOB m1[11])
{
    int i,max,index=0;
    max=m1[index].price;
    for(i=1;i<4;i++)
    {
        if(m1[i].price>max)
        {
            max=m1[i].price;
            index=i;
        }
    }
    printf("Mobile with highest price:\n");
    display_result(m1,index);
    printf("\n");
}
void max_battery(MOB m1[11])
{
    int i,max,index=0;
    max=m1[index].battery;
    for(i=1;i<4;i++)
    {
        if(m1[i].battery>max)
        {
            max=m1[i].battery;
            index=i;
        }
    }
    printf("Mobile with longest battery life:\n");
    display_result(m1,index);
}

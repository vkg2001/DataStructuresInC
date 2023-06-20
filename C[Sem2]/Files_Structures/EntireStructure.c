#include<stdio.h>
typedef struct mobile
{
    char brand[20],series[20];
    int price,pixels;
    float memory;
    int battery;
}MOB;
MOB read(MOB);
void display(MOB);
int main()
{
    MOB m1;
    m1=read(m1);
    display(m1);
    return 0;
}
MOB read(MOB m1)
{
    printf("Enter Brand:");
    gets(m1.brand);
    printf("Enter Series:");
    gets(m1.series);
    printf("Enter Price:");
    scanf("%d",&m1.price);
    printf("Enter Camera:");
    scanf("%d",&m1.pixels);
    printf("Enter Memory:");
    scanf("%f",&m1.memory);
    printf("Enter Battery:");
    scanf("%d",&m1.battery);
    return m1;
}
void display(MOB m1)
{
    printf("Brand\tSeries\tPrice\tCamera\tMemory\tBattery\n");
    printf("%s\t%s\t%d\t%d\t%.2f\t%d\n",m1.brand,m1.series,m1.price,m1.pixels,m1.memory,m1.battery);
}

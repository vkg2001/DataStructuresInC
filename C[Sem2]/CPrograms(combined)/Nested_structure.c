#include<stdio.h>
typedef struct memory
{
    int memo;
}M;
typedef struct cell_phone
{
     char name[10];
     int price;
     M mem;
}CP;
void read(CP[],int);
void print(CP[],int);
void main()
{
    CP c1[10];
    int n;
    printf("ENTER NO. OF PHONES:\t");
    scanf("%d",&n);
    if(n<1||n>10)
    {
        printf("INVALID");
    }
    else
    {
        read(c1,n);
        print(c1,n);
    }
}
void read(CP c1[10],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("ENTER MOBILE NAME, PRICE & MEMORY:\n");
        scanf("%s %d %d",c1[i].name, &c1[i].price, &c1[i].mem.memo);
    }
}
void print(CP c1[10],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("MOBILE NAME\tPRICE\tMEMORY\n");
        printf("%s\t\t%d\t%d\n",c1[i].name,c1[i].price,c1[i].mem.memo);
    }
}

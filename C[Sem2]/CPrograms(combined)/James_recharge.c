#include<stdio.h>
typedef struct James_recharge
{
    float price;
    char ex[15];
}JR;
void read(JR a[5],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("Enter the amount ");
        scanf("%f%*c",&a[i].price);
        printf("Enter the amount spent for ");
        gets(a[i].ex);
    }
}
void total(JR b[5],int n)
{
    float sum=0;
    int i,j;
    float h=b[0].price;
    for(i=0;i<n;i++)
        sum=sum+b[i].price;
    printf("Total amount spent is %5.2f\n",sum);
    printf("The highest amount spent in single transaction is \n");
    for(i=1;i<n;i++)
        if(b[i].price>h)
        {
            h=b[i].price;
            j=i;
        }
    printf("The amount was %5.0f\n",b[j].price);
    printf("The amount was spent for ");
    puts(b[j].ex);
}
void main()
{
    JR a[5];
    int n;
    printf("Enter the number of transaction ");
    scanf("%d",&n);
    read(a,n);
    total(a,n);
}

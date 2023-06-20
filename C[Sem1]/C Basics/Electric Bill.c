#include<stdio.h>
void main()
{
    int id,u;
    float bill;
    printf("Enter the ID and Units consumed:");
    scanf("%d%d",&id, &u);
    if(u<200)
        bill=u*1.2;
    else if(u>=200&&u<400)
        bill=199*1.2+(u-199)*1.5;
    else if(u>=400&&u<600)
        bill=199*1.2+200*1.5+(u-399)*1.8;
    else if(u>=600)
        bill=199*1.2+200*1.5+(200)*1.8*(u-599)*2;
    if(bill<100)
        bill=100;
    else if(bill>400)
    bill=bill+15.0/100*bill;
    printf("ID=%d\nBill=%f",id,bill);
}

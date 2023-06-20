#include<stdio.h>
void main()
{
    int a,a1,a2,a3,a4,a5,ca=0,cv=0;
    char type;
    printf("Enter 5 tosses:");
    scanf("%d%d%d%d%d",&a1,&a2,&a3,&a4,&a5);
    a=a1+a2+a3+a4+a5;
    if(a<=7)
        printf("Amit will eat Cake");
    else
        printf("Vikas will eat Cake");
}

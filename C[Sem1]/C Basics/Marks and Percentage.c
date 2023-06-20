#include<stdio.h>
void main()
{
    int m1,m2,m3,m4,m5;
    float tm, per;
    printf("Enter marks of 5 subjects:");
    scanf("%d%d%d%d%d",&m1,&m2,&m3,&m4,&m5);
    tm=m1+m2+m3+m4+m5;
    per=tm/5;
    printf("Aggregate Marks:%f", tm);
    printf("Percentage:%f", per);
}

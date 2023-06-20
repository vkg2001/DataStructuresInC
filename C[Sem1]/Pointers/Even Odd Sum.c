#include<stdio.h>
void sum(int *a,int n,int *e,int *o);
void main()
{
    int i,num,es=0,os=0;
    printf("ENTER THE NO. OF NO'S: ");
    scanf("%d",&num);
    int a[num];
    for(i=0;i<num;i++)
    {
        scanf("%d",&(*(a+i)));
    }
    sum(a,num,&es,&os);
    printf("SUM OF EVEN: %d\nSUM OF ODD : %d",es,os);
}
void sum(int *a,int n,int *e,int *o)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(*(a+i)%2==0)
        {
            *e+=*(a+i);
        }
        else
        {
            *o+=*(a+i);
        }
    }
}

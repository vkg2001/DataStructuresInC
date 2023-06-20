#include<stdio.h>
#include<string.h>
typedef struct tesm
{
    char name[20];
    int runs,avg;
}PLR;
void read(PLR [],int);
void search(PLR [],int);
void high(PLR [],int);
void main()
{
    PLR p[100];
    int n;
    printf("ENTER THE NUMBER OF PLAYERS:\t");
    scanf("%d",&n);
    read(p,n);
    high(p,n);
    search(p,n);
}
void read(PLR p[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("PLAYER NAME\tRUNS\tAVERAGE\t\n");
        scanf("%s %d %d",p[i].name,&p[i].runs,&p[i].avg);
    }
}
void high(PLR p[],int n)
{
    int i,j;
    PLR temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(p[j].runs<p[j+1].runs)
            {
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
    printf("THE FINAL TEAM IS:\n");
    printf("PLAYER\tRUNS\tAVERAGE\n");
    for(i=0;i<3;i++)
    {
        printf("%s\t%d\t%d\n",p[i].name,p[i].runs,p[i].avg);
    }
    printf("%s\t%d\t%d\n",p[n-1].name,p[n-1].runs,p[n-1].avg);
}
void search(PLR p[],int n)
{
    int temp,i;
    char s[]="Rajat";
    for(i=0;i<n;i++)
    {
        temp=strcmp(p[i].name,s);
        if(temp==0)
            printf("%s\t%d\t%d\n",p[i].name,p[i].runs,p[i].avg);
    }
}

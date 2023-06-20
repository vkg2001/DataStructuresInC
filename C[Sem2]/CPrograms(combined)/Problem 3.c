#include<stdio.h>
#include<string.h>
typedef struct team
{
    char name[20];
    char state[20];
    float avg;
    int runs;
}PLR;
void read(PLR[],int);
void display(PLR[],int);
void highruns(PLR[]);
void lowruns(PLR[],int);
int rajat(PLR[],int);
void sort(PLR[],int);
int main( )
{
    int max,min,name,n;
    PLR p[11];
    printf("ENTER THE NUMBER OF PLAYERS:\n");
    scanf("%d",&n);
    if(n<4||n>20)
    {
        printf("INVALID INPUT");
    }
    else
    {
        read(p,n);
        printf("\nBEFORE SORTING:\n");
        display(p,n);
        sort(p,n);
        printf("\nAFTER SORTING:\n");
        display(p,n);
        name=rajat(p,n);
        printf("\nPLAYERS DETAILS: \n");
        printf("\nFIRST THREE HIGHEST SCORES\n");
        highruns(p);
        printf("\nLEAST RUN SCORER\n");
        lowruns(p,n);
        printf("\nPLAYER NAMED RAJAT\n");
        printf("\nPLAYER NAME\tTEAM NAME\tAVERAGE\t\tRUNS\n");
        printf("%s\t\t%s\t\t%0.2f\t\t%d\n",p[name].name,p[name].state,p[name].avg,p[name].runs);
    }
    return 0;
}
void read(PLR p[11],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("PLAYER NAME\tTEAM NAME\tAVERAGE\tRUNS\t\n");
        scanf("%s %s %f %d",p[i].name,p[i].state,&p[i].avg,&p[i].runs);
    }
}

void display(PLR p[11],int n)
{
    int i;
    printf("PLAYER NAME\tTEAM NAME\tAVERAGE\tRUNS\t\n");
    for(i=0;i<n;i++)
    {
        printf("%s\t\t%s\t\t%0.2f\t\t%d\n",p[i].name,p[i].state,p[i].avg,p[i].runs);
    }
}
void sort(PLR p[11],int n)
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
}
void highruns(PLR p[20])
{
    int i;
    printf("PLAYER NAME\tTEAM NAME\tAVERAGE\tRUNS\t\n");
    for(i=0;i<3;i++)
    {
        printf("%s\t\t%s\t\t%0.2f\t\t%d\n",p[i].name,p[i].state,p[i].avg,p[i].runs);
    }
}

void lowruns(PLR p[20],int n)
{
    printf("PLAYER NAME\tTEAM NAME\tAVERAGE\tRUNS\t\n");
    printf("%s\t\t%s\t\t%0.2f\t\t%d\n",p[n-1].name,p[n-1].state,p[n-1].avg,p[n-1].runs);
}
int rajat(PLR p[11],int n)
{
    int i,index,value;
    char str[]="Rajat";
    for(i=0;i<n;i++)
    {
        value=strcmpi(p[i].name,str);
        if(value==0)
        {
            index=i;
            break;
        }
    }
    return index;
}

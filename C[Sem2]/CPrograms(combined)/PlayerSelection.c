#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct team
{
   char name[20];
   int runs;
}TM;
void read(TM [],int);
void display(TM [],int);
void high(TM [],int);
void low(TM [],int);
void last(TM [],int);
int main()
{
    TM p[100];
    int n;
    printf("ENTER NO. OF PLAYERS:\n");
    scanf("%d",&n);
    read(p,n);
    display(p,n);
    high(p,n);
    low(p,n);
    last(p,n);
    return 0;
}
void read(TM p[],int n)
  {
    int i;
    printf("ENTER PLAYER DETAILS:\n");
    for(i=0;i<n;i++)
    {
        printf("ENTER PLAYER %d DETAILS:\t",p[i]);
        printf("ENTER NAME OF PLAYER:\t");
        scanf("%s",p[i].name);
        printf("ENTER RUNS SCORED:\t");
        scanf("%d",&p[i].runs);
    }
  }
  void display(TM p[],int n);
  {
      int i;
      printf("\n\nENTERED DETAILS:\n\n");
      for(i=0;i<n;i++)
    {
        printf("PLAYER %d DETAILS:\t",p[i]);
        printf("NAME OF PLAYER:\t");
        scanf("%s",p[i].name);
        printf("RUNS SCORED:\t");
        scanf("%d",p[i].runs);
    }
  }
  void high(TM p[],int n);
  {

  }
void read( PLR t[11])
{
    int i;
    printf("Player name\tTeam name\tAverage\tCareer Runs\t .Leave Space and enter \n");
    for(i=0;i<5;i++)
    {
        scanf("%s %s %f %d",t[i].player_name,t[i].state_name,&t[i].average,&t[i].total_runs);
    }
}

void display(PLR t[11])
{
    int i;
    printf("\nPlayer Name\tTeam Name\tAverage\t\tCareer Runs\n");
    for(i=0;i<5;i++)
    {
        printf("%s\t\t%s\t\t%0.2f\t\t%d\n",t[i].player_name,t[i].state_name,t[i].average,t[i].total_runs);
    }
}

int highest_runs(PLR t[11])
{
    int i,high,index=0;
    high=t[index].total_runs;
    for(i=1; i<5; i++)
    {
        if(t[i].total_runs>high)
        {
            high=t[i].total_runs;
            index=i;
        }
    }
    return index;
}

int lowest_runs(PLR t[11])
{
    int i, low, index=0;
    low=t[index].total_runs;
    for(i=1; i<5; i++)
    {
        if(t[i].total_runs<low)
        {
            low=t[i].total_runs;
            index=i;
        }
    }
    return index;
}

int r_player(PLR t[11])
{
    int i,index,value;
    char str[] = "Rajat";
    for(i=0;i<5;i++)
    {
        value=strcmpi(t[i].player_name,str);
        if(value==0)
        {
            index=i;
            break;
        }
    }
    return index;
}

void disp(PLR t[11],int i)
{
        printf("%s\t\t%s\t\t%0.2f\t\t%d\n",t[i].player_name,t[i].state_name,t[i].average,t[i].total_runs);
}

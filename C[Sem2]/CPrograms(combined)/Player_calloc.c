#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct players
{
    char p_name[20], t_name[10];
    int odi_rank, centuries, runs;
}PLR;
void read(PLR *bcrptr);
void display(PLR *bcrptr);

int main()
{
    PLR *bcrptr;
    bcrptr=malloc(1);
    if(bcrptr==NULL)
    {
        printf("Memory not allocated.");
        exit (0);
    }
    else
    {
        printf("Enter Player Details\n");
        read(bcrptr);
        printf("\n\nPlayer Details\n");
        display(bcrptr);
    }
    return 0;
}

void read(PLR *bcrptr)
{
    int i;
    printf("Enter Player name, team name, ODI rank, centuries, runs scored\n");
    scanf("%s%s%d%d%d", bcrptr->p_name, bcrptr->t_name, &bcrptr->odi_rank,&bcrptr->centuries, &bcrptr->runs);
}

void display(PLR *bcrptr)
{
    int i;
    printf("Name\t\tTeam\tODI Rank\tCenturies\tRuns\n");
    printf("%s\t\t%s\t%d\t\t%d\t\t%d\n",bcrptr->p_name, bcrptr->t_name,bcrptr->odi_rank,bcrptr->centuries,bcrptr->runs);
}

/*
3) Varun Finchi is a manger of BCR franchise team, where he has to select 5 players to make squad full for playing in PPL League.
He contacts Lord Hassan who is an analyst of BCR team, where he has all the player details.
Varun Finchi selects 3 players who have highest runs in their career, one who has least runs in his career and one more player who has Name ‘Rajat’ .
Please help Varun Finchi to select players for BCR team.
*/

/*
virat india 1 40 25000
dhoni india 2 50 32000
rohit india 3 30 29000
ashwin india 12 10 12000
rajat india 34 2 2554
raina india 20 34 12455
Rajat india 10 12 4832
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct players
{
    char p_name[20], t_name[10];
    int odi_rank, centuries, runs;
}TEAM;

void read(TEAM *bcrptr, int n )
{
    int i;
    printf("Enter Player name, team name, odi rank, centuries, runs scored\n");
    for(i=0;i<n;i++)
    {
        scanf("%s%s%d%d%d", bcrptr->p_name, bcrptr->t_name, &bcrptr->odi_rank,&bcrptr->centuries, &bcrptr->runs);
        bcrptr++;
    }
}

void display(TEAM *bcrptr, int n)
{
    int i;
    printf("\nTeam Details\n");
    printf("Name\t\tTeam\tODi Rank\tCenturies\tRuns\n");
    for(i=0;i<n;i++)
    {
         printf("%s\t\t%s\t%d\t\t%d\t\t%d\n",bcrptr->p_name, bcrptr->t_name,bcrptr->odi_rank,bcrptr->centuries,bcrptr->runs);
         bcrptr++;
    }
}

void sort_descending(TEAM *bcrptr, int n)
{
    TEAM *bptr;
    TEAM *temp=calloc(1, sizeof(TEAM));
    int i,j;
    bptr=bcrptr;
    for(i=0;i<n-1;i++)
    {
        bcrptr=bptr;
        for(j=0;j<(n-1-i); j++)
        {
            if( bcrptr->runs < (bcrptr+1)->runs)
            {
                *temp = *bcrptr;
                *bcrptr = *(bcrptr+1);
                *(bcrptr+1) = *temp;
            }
            bcrptr++;
        }
    }
    printf("\nSelected Team Players are\n");
    printf("Name\t\tTeam\tODi Rank\tCenturies\tRuns\n");
    bcrptr=bptr;
    //3 players highest runs scorers.
    for(i=0;i<3;i++)
    {
        printf("%s\t\t%s\t%d\t%d\t%d\n",bcrptr->p_name, bcrptr->t_name,bcrptr->odi_rank,bcrptr->centuries,bcrptr->runs);
        bcrptr++;
    }

    //1 player least runs scorer
    i=0;
    bcrptr=bptr;
    for(i=0;i<n-1;i++)
    {
        bcrptr++;
    }
    printf("%s\t\t%s\t%d\t%d\t%d\n",bcrptr->p_name, bcrptr->t_name,bcrptr->odi_rank,bcrptr->centuries,bcrptr->runs);
    bcrptr=bptr;

    // 1 player with name = Rajat.
    for(i=0;i<n;i++)
    {
        if(strcmp(bcrptr->p_name,"Rajat") == 0 )
        {
            printf("%s\t\t%s\t%d\t%d\t%d\n",bcrptr->p_name, bcrptr->t_name,bcrptr->odi_rank,bcrptr->centuries,bcrptr->runs);
            break;
        }
        bcrptr++;
    }
}

int main()
{
    TEAM *bcrptr;
    int n;
    printf("Enter number of player details to read\n");
    scanf("%d", &n);
    bcrptr=malloc(n*1);
    read(bcrptr, n);
    printf("BCR Team Details\n");
    display(bcrptr, n);
    sort_descending(bcrptr, n);
    return 0;
}

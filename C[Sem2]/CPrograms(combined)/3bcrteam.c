/*
3) Varun Finchi is a manger of BCR franchise team, where he has to select 5 players to make squad full for playing in PPL League.
He contacts Lord Hassan who is an analyst of BCR team, where he has all the player details.
Varun Finchi selects 3 players who have highest runs in their career, one who has least runs in his career and one more player who has Name ‘Rajat’ .
Please help Varun Finchi to select players for BCR team.
*/

#include<string.h>
#include<stdio.h>
typedef struct players
{
    char p_name[20], t_name[10];
    int runs;
}TEAM;

void read(TEAM bcr[10], int n)
{
    int i;
    printf("Enter Player name, team name, runs scored\n");
    for(i=0;i<n;i++)
    {
        scanf("%s %s %d", bcr[i].p_name, bcr[i].t_name, &bcr[i].runs);
    }
}

void display(TEAM bcr[10], int n)
{
    int i;
    printf("\nTeam Details\n");
    printf("Name\t\tTeam\tRuns\n");
    for(i=0;i<n;i++)
    {
        printf("%s\t\t%s\t%d\n",bcr[i].p_name, bcr[i].t_name,bcr[i].runs);
    }
}

void sort_descending(TEAM bcr[10], int n)
{
    TEAM temp;
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<(n-1-i); j++)
        {
            if(bcr[j].runs < bcr[j+1].runs)
            {
                temp = bcr[j];
                bcr[j] = bcr[j+1];
                bcr[j+1] = temp;
            }
        }
    }
    printf("\nSelected Team Players are\n");
    printf("Name\t\tTeam\tRuns\n");

    //3 players highest runs scorers.
    for(i=0;i<3;i++)
    {
        printf("%s\t\t%s\t%d\n",bcr[i].p_name, bcr[i].t_name,bcr[i].runs);
    }

    //1 player least runs scorer
    printf("%s\t\t%s\t%d\n",bcr[n-1].p_name, bcr[n-1].t_name,bcr[n-1].runs);

    // 1 player with name = Rajat.
    for(i=0;i<n;i++)
    {
        if(strcmp(bcr[i].p_name,"Rajat") == 0 )
        {
            printf("%s\t\t%s\t%d\n",bcr[i].p_name, bcr[i].t_name,bcr[i].runs);
            break;
        }
    }
}

int main()
{
    TEAM bcr[10];
    int n;
    printf("Enter number of player details to read\n");
    scanf("%d", &n);
    read(bcr, n);
    printf("BCR Team Details\n");
    display(bcr, n);
    sort_descending(bcr, n);
    return 0;
}

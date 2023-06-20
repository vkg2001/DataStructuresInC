#include<stdio.h>
typedef struct cricket_player
{
    char name[20];
    int odi_rank;
    int centuries;
    float avg;
}plr;
void display(char [], int, int);
int main()
{
    plr p1={"Virat",1,39,59.9};
    display(p1.name,p1.odi_rank,p1.centuries);
    return 0;
}
void display(char name[20], int odi_rank, int centuries)
{
    printf("Name\tODI Rank\tCenturies\n");
    printf("%s\t%d\t\t%d",name,odi_rank,centuries);
}

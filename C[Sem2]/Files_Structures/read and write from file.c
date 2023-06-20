#include<stdio.h>

typedef struct player
{
char player_name[20];
int odi_rank;
int man_of_matches;
int man_of_series;
int no_of_centuries;
} PLR;
void read_from_file(FILE *);
void display_from_file(FILE *);

int main()
{
FILE *fp;
fp=fopen("input.txt","w");
read_from_file(fp);
fclose(fp);
fp=fopen("input.txt","r");
display_from_file(fp);
fclose(fp);
return 0;
}
void read_from_file(FILE *fptr)
{
PLR p1;
printf("Enter player name ,odi rank,man_of_matches,man_of_series,no_of_centuries\n");
scanf("%s %d %d %d %d",p1.player_name,&p1.odi_rank,&p1.man_of_matches,&p1.man_of_series,&p1.no_of_centuries);
fprintf(fptr,"%s %d %d %d %d ",p1.player_name,p1.odi_rank,p1.man_of_matches,p1.man_of_series,p1.no_of_centuries);
}

void display_from_file(FILE *fptr)
{
PLR p1;
printf("player name\todi rank\tman_of_matches\tman_of_series\tno_of_centuries\n");
fscanf(fptr,"%s %d %d %d %d",p1.player_name,&p1.odi_rank,&p1.man_of_matches,&p1.man_of_series,&p1.no_of_centuries);

printf("%s\t %d\t %d\t %d\t %d\t",p1.player_name,p1.odi_rank,p1.man_of_matches,p1.man_of_series,p1.no_of_centuries);

}


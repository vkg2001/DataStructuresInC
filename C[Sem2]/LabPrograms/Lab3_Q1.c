#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student
{
    char name[20],course[10];
    int sem;
    int fees;
    int roll_no;
    int id;
}ST;

void read(FILE *,int);
void display(FILE *,int);
void fees_paid(FILE *,int);

void main()
{
    int n;
    printf("ENTER THE NUMBER OF STUDENTS:\n");
    scanf("%d",&n);
    FILE *fp;
    read(fp,n);
    display(fp,n);
    fees_paid(fp,n);
}
void read(FILE *fp,int n)
{
    ST s[20];
    int i;
    fp=fopen("studentrecord.txt","w");
    printf("\nENTER ROLL NO., NAME, COURSE, FEES, SEM:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d%s%s%d%d",&s[i].id,s[i].name,s[i].course,&s[i].fees,&s[i].sem);
        fprintf(fp,"%d%s%s%d%d",s[i].id,s[i].name,s[i].course,s[i].fees,s[i].sem);
    }
    fclose(fp);
}
void display(FILE *fp,int n)
{
    int i;
    ST s[20];
    fp=fopen("studentrecord.txt","r");
    while(!feof(fp))
    {
    fscanf(fp,"%d%s%s%d%d",&s[i].id,s[i].name,s[i].course,&s[i].fees,&s[i].sem);
    i++;
    }
    printf("\nSTUDENT DETAILS ARE:\n");
    for(i=0; i<n; i++)
    {
            printf("\nSTUDENT ID:\t");
            printf("%d",s[i].id);
            printf("\nSTUDENT NAME:\t");
            printf("%s",s[i].name);
            printf("\nCOURSE:\t");
            printf("%s",s[i].course);
            printf("\nFEES:\t");
            printf("%d",s[i].fees);
            printf("\nSTUDENT SEM:\t");
            printf("%d",s[i].sem);
    }

    fclose(fp);
}
void fees_paid(FILE *fp,int n)
{
    int i;
    ST s[20];
    fp=fopen("studentrecord.txt","r");
    while(!feof(fp))
    {
        fscanf(fp,"%d%s%s%d%d",&s[i].id,s[i].name,s[i].course,&s[i].fees,&s[i].sem);
        i++;
    }
    int sum=0;
    for(i=0; i<n; i++)
    {
        sum=sum+s[i].fees;
    }
    printf("\n\nTOTAL FEES PAID: %d\n",sum);
}

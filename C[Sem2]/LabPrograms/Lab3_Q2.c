#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student
{
    char name[20];
    int marks;
}ST;

void read(FILE *,int);
void display(FILE *,int);

void main()
{
    int n;
    printf("ENTER THE NUMBER OF STUDENTS:\n");
    scanf("%d",&n);
    FILE *fp;
    read(fp,n);
    display(fp,n);
}
void read(FILE *fp,int n)
{
    ST s[20];
    int i;
    fp=fopen("studentrecord.txt","a");
    for(i=0;i<n;i++)
    {
        printf("\nENTER NAME & MARKS OF %d STUDENT:\n", i+1);
        scanf("%s\t%d",s[i].name,&s[i].marks);
        fprintf(fp,"%s\t%d\n",s[i].name,s[i].marks);
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
    fscanf(fp,"%s\t%d",s[i].name,&s[i].marks);
    i++;
    }
    printf("\nSTUDENT DETAILS ARE:\n");
    for(i=0; i<n; i++)
    {
            printf("\nSTUDENT NAME:\t");
            printf("%s",s[i].name);
            printf("\nSTUDENT MARKS:\t");
            printf("%d",s[i].marks);
    }
    fclose(fp);
}

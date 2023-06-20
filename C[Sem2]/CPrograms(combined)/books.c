#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Books
{
    char name[50],title[50],category[25];
}BK;

void write(FILE *fp,BK b[100],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("ENTER NAME, TITLE & CATEGORY:\n");
        scanf("%s%s%s",b[i].name,b[i].title,b[i].category);
        fprintf(fp,"%s\t%s\t%s\n",b[i].name,b[i].title,b[i].category);
    }
}

void print(FILE *fp,BK b[100],int n)
{
    printf("ENTERED DETAILS:\n");
    for(int i=0;i<n;i++)
    {
        printf("NAME\tTITLE\tCATEGORY\t OF BOOK %d:\n",i+1);
        printf("%s\t%s\t%s\n",b[i].name,b[i].title,b[i].category);
        printf("\n");
    }
}
void count(BK b[100],int n)
{
    char s[5][15]={"Novel","Arts","GK","Sports","Entertainment"};
    int i,max,temp;
    int x[5]={0,0,0,0,0};
    for(i=0;i<n;i++)
    {
        if(strcmpi(b[i].category,"Novel")==0)
        {
            x[0]++;
        }
        else if(strcmpi(b[i].category,"Arts")==0)
        {
            x[1]++;
        }
        else if(strcmpi(b[i].category,"GK")==0)
        {
            x[2]++;
        }
        else if(strcmpi(b[i].category,"Sports")==0)
        {
            x[3]++;
        }
        else if(strcmpi(b[i].category,"Entertainment")==0)
        {
            x[4]++;
        }
    }
    max=x[0];
    temp=0;
    for(i=1;i<5;i++)
    {
        if(x[i]>max)
        {
            max=x[i];
            temp=i;
        }
    }
    printf("%s",s[temp]);
}

int main()
{
    BK b[100];
    FILE *fp;
    int n;
    printf("ENTER NUMBER OF BOOKS:\t");
    scanf("%d",&n);
    if(n<1 || n>100)
    {
        exit(0);
    }
    else
    {
        fp=fopen("books.txt","a+");
        write(fp,b,n);
        print(fp,b,n);
        count(b,n);
        fclose(fp);
    }
    return 0;
}

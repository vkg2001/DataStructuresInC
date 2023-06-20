#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct bookdetails
{
   char name[20];
   char author[20];
   int isbn;
   int cost;
   int pages;
};
typedef struct bookdetails BD;
void read(BD [],int);
void display(BD [],int);
void sort(BD [],int);
void search(BD [],int);
void main()
  {
      BD b[100];
      int n;
      printf("ENTER NO. OF BOOKS\n");
      scanf("%d",&n);
      printf("\n");
      read(b,n);
      display(b,n);
      sort(b,n);
      display(b,n);
      search(b,n);
  }
  void read(BD b[],int n)
  {
    int i;
    for(i=0;i<n;i++)
    {
        printf("ENTER DETAILS OF BOOOK:\n");
        printf("ENTER NAME OF BOOK:\t");
        scanf("%s",b[i].name);
        printf("ENETR NAME OF AUTHOR:\t");
        scanf("%s",b[i].author);
        printf("ENTER ISBN NUMBER:\t");
        scanf("%d",&b[i].isbn);
        printf("ENTER COST:\t\t");
        scanf("%d",&b[i].cost);
        printf("ENTER NO. OF PAGES:\t");
        scanf("%d",&b[i].pages);
        printf("\n");
    }
  }
  void display(BD b[],int n)
  {
    int i;
    printf("\nENTERED DETAILS:\n\n");
    for(i=0;i<n;i++)
        {
            printf("NAME OF BOOK:\t");
            printf("%s\n",b[i].name);
            printf("NAME OF AUTHOR:\t");
            printf("%s\n",b[i].author);
            printf("ISBN NUMBER:\t");
            printf("%d\n",b[i].isbn);
            printf("COST:\t\t");
            printf("%d\n",b[i].cost);
            printf("NUMBER OF PAGES:\t");
            printf("%d\n",b[i].pages);
            printf("\n");
        }
  }
  void sort(BD b[],int n)
  {
    int i,j;
    printf("\nSORTED DETAILS:\n\n");
    BD temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(b[j].isbn>b[j+1].isbn)
            {
                temp=b[j];
                b[j]=b[j+1];
                b[j+1]=temp;
            }
        }
    }
}
  void search(BD b[],int n)
  {
      int i,temp,r=0;
      printf("\n\nENTER ISBN NUMBER\t");
      scanf("%d",&temp);
      printf("\n");
      for(i=0;i<n;i++)
      {
         if(temp==b[i].isbn)
         {
           r=1;
           printf("NAME OF BOOK:\t");
           printf("%s\n",b[i].name);
           printf("NAME OF AUTHOR:\t");
           printf("%s\n",b[i].author);
           printf("ISBN NUMBER:\t");
           printf("%d\n",b[i].isbn);
           printf("COST:\t\t");
           printf("%d\n",b[i].cost);
           printf("NUMBER OF PAGES:\t");
           printf("%d\n",b[i].pages);
           printf("\n");
         }
     }
     if(r==0)
            {
              printf("NO MATCHES FOUND!\n");
            }
  }

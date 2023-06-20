#include<stdio.h>
void sum(int n,int m,int a[n][m],int b[n][m],int c[n][m]);
void readarray(int n,int m,int a[n][m],int b[n][m]);
void printarray(int n,int m,int a[n][m],int b[n][m]);
void main()
{
    int n,m;
    printf("Enter value of N: ");
    scanf("%d",&n);
    printf("Enter value of M: ");
    scanf("%d",&m);
    int a[n][m],b[n][m],c[n][m];
    readarray(n,m,a,b);
    printarray(n,m,a,b);
    sum(n,m,a,b,c);
}
void readarray(int n,int m,int a[n][m],int b[n][m])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
}
void printarray(int n,int m,int a[n][m],int b[n][m])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
          printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
          printf("%d\t",b[i][j]);
        }
        printf("\n");
    }
}
void sum(int n,int m,int a[n][m],int b[n][m],int c[n][m])
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
          c[i][j]=a[i][j]+b[i][j];
          printf("%d\t",c[i][j]);
        }
        printf("\n");
    }
}

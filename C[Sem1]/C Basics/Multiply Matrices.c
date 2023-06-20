#include<stdio.h>
void mul(int a[100][100],int b[100][100],int c[100][100],int,int);
void readarray(int a[100][100],int b[100][100],int c[100][100],int,int);
void printarray(int a[100][100],int b[100][100],int c[100][100],int,int);
void main()
{
    int a[100][100],b[100][100],c[100][100],n,m;
    readarray(a,b,c,n,m);
    printarray(a,b,c,n,m);
    mul(a,b,c,n,m);
}
void readarray(int a[100][100],int b[100][100],int c[100][100],int n,int m)
{
    printf("Enter the value of rows:");
    scanf("%d",&n);
    printf("\nEnter the value of colums:");
    scanf("%d",&m);
    printf("\n");
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
void printarray(int a[100][100],int b[100][100],int c[100][100],int n,int m)
{
    for(int i=0;i<n;i++)
    {
       for(int j=0;j<m;j++)
    {
        printf("%d",a[i][j]);
    }
    printf("\n");
    }
    for(int i=0;i<n;i++)
    {
       for(int j=0;i<m;j++)
    {
        printf("%d",b[i][j]);
    }
    printf("\n");
    }
}
void mul(int a[100][100],int b[100][100],int c[100][100],int n,int m)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            c[i][j]=0;
            for(int k=0;k<m;k++)
            {
                c[i][j]+=a[i][k]*b[k][j];
                printf("Multiplied elements are:\n");
                printf("%d\t",c[i][j]);
            }
        }
    }
}

#include<stdio.h>
int mul(int,int,int,int,int a[100][100],int b[100][100]);
void readarray(int,int,int,int,int a[100][100],int b[100][100]);
void printarray(int,int,int,int,int a[100][100],int b[100][100]);
int main()
{
    int n,m,p,q,a[100][100],b[100][100];
    printf("Enter the number of rows of matrix A: ");
    scanf("%d",&n);
    printf("Enter the number of columns of matrix A: ");
    scanf("%d",&m);
    printf("Enter the number of rows of matrix B: ");
    scanf("%d",&p);
    printf("Enter the number of columns of matrix B: ");
    scanf("%d",&q);
    if(m!=p)
    {
        printf("Invalid Input");
        return 1;
    }
    readarray(n,m,p,q,a,b);
    printarray(n,m,p,q,a,b);
    mul(n,m,p,q,a,b);
    return 0;
}
void readarray(int n,int m,int p,int q,int a[100][100],int b[100][100])
{
    printf("Enter  array A elements: ");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter  array B elements: ");
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<q;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
}
void printarray(int n,int m,int p,int q,int a[100][100],int b[100][100])
{
    printf("Matrix A: \n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
    printf("Matrix B: \n");
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<q;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}
int mul(int n,int m,int p,int q,int a[100][100],int b[100][100])
{
    int i,j,c[100][100];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<q;j++)
        {
            c[i][j]=0;
            for(int k=0;k<p;k++)
            {
               c[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(j=0;j<q;j++)
        {
            printf("%d\t",c[i][j]);
        }
        printf("\n");
    }
}

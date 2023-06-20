
#include<stdio.h>
void read(int a[100][100],int, int);
void display(int a[100][100],int, int);
int main()
{
    int m, n,a[100][100];

    printf("Enter number of row and column: ");
    scanf("%d %d",&m,&n);
read(a,m,n);
display(a,m,n);
}

void read(int a[100][100],int m,int n)
{
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("Enter arr[%d][%d]: ",i,j);
            scanf("%d", &a[i][j]);
        }
        printf("\n");
    }
}
void display(int a[100][100],int m,int n)
{
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}

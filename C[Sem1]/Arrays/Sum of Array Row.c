#include<stdio.h>
void readarray(int n,int m,int a[10][10])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
}
void printarray(int n,int m,int a[10][10])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}
void sumofrow(int n,int m,int a[10][10])
{

    for(int i=0;i<n;i++)
    {
        int ecount=0,ocount=0;
        int sum=0;
        for(int j=0;j<m;j++)
        {
            {if(a[i][j]%2!=0)
            {
                ocount++;
            }
            else
            {
                ecount++;
            }
            }
            sum+=a[i][j];
        }
        printf("Sum= %d\n",sum);
        printf("Even count: %d\n",ecount);
        printf("Odd count: %d\n",ocount);
    }
}
void main()
{
    int a[10][10],n,m,i,j;
    printf("Enter the N: ");
    scanf("%d",&n);
    printf("Enter the M: ");
    scanf("%d",&m);
    readarray(n,m,a);
    printarray(n,m,a);
    sumofrow(n,m,a);
}

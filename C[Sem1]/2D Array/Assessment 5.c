#include<stdio.h>
void maximum(int a[100][100],int n,int m);
void average(int a[100][100],int n,int m);
void readarray(int a[100][100],int n,int m);
void printarray(int a[100][100],int n,int m);
int main()
{
    int n,m,a[100][100];
    printf("Enter the number of Cities: \n");
    scanf("%d",&n);
    printf("Enter the number of days: \n");
    scanf("%d",&m);
    readarray(a,n,m);
    printarray(a,n,m);
    maximum(a,n,m);
    average(a,n,m);
    return 0;
}
void readarray(int a[100][100],int n,int m)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
}
void printarray(int a[100][100],int n,int m)
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
void maximum(int a[100][100],int n,int m)
{
    for(int i=0;i<n;i++)
    {
        int max=a[i][0];
        for(int j=0;j<m;j++)
        {
            if(a[i][j]>max)
            {
                max=a[i][j];
            }
        }
        printf("Maximum temperature in city %d is: %d",i+1,max);
        printf("\n");
    }
}
void average(int a[100][100],int n,int m)
{
    for(int i=0;i<n;i++)
        {
            int sum=0;
            float avg;
            for(int j=0;j<m;j++)
            {
                sum+=a[i][j];
            }
            avg=(float)sum/(float)m;
            printf("The average of temperatures of city %d is %f",i+1,avg);
            printf("\n");
        }
}

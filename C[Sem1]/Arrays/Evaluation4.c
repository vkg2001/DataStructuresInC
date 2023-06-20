#include<stdio.h>
void order(int [],int);
void readarray(int [],int);
void printarray(int [],int);
void main()
{
    int n,a[100];
    printf("Enter the number of students: ");
    scanf("%d",&n);
    readarray(a,n);
    order(a,n);
}
void readarray(int a[],int n)
{
    printf("Enter the elements in order: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}
void order(int a[],int n)
{
    int i,j,temp,sum=0,avg;
    for(int i=1;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    printf("The admission order is as follows:");
    for(j=0;j<n;j++)
    {
        printf("%d\t",a[j]);
    }
    for(j=0;j<n;j++)
    {
        sum+=a[j];
    }
    avg=sum/n;
    printf("The students getting Scholarship are:");
    for(j=0;j<n;j++)
    {
        if(a[j]<avg)
        printf("%d\t",a[j]);
    }
    printf("%d\t",a[j]);
}
void printarray(int a[],int n)
{
    printf("The ranks are as follows:");
    for(int i=0;i<n-1;i++)
    {
        printf(" %d ",a[i]);
    }
    printf("\n\n");
}

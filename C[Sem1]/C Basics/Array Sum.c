#include<stdio.h>
float sum(int [],int);
void readarray(int [],int);
void printarray(int [],int);
void main()
{
    int n,a[n],ans;
    printf("Enter the number of elements");
    scanf("%d",&n);
    readarray(a,n);
    printarray(a,n);
    ans=sum(a,n);
    printf("\nSum= %d",ans);
}
void readarray(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}
void printarray(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}
float sum(int a[],int n)
{
    int i;
    float sum=0.0;
    for(i=0;i<n;i++)
    {
        sum+=a[i];
    }
    return sum;
}


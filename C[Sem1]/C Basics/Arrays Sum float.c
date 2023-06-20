#include<stdio.h>
float sum(float [],int);
void readarray(float [],int);
void printarray(float [],int);
void main()
{
    int n;
    float ans,a[n];
    printf("Enter the number of elements");
    scanf("%d",&n);
    readarray(a,n);
    printarray(a,n);
    ans=sum(a,n);
    printf("\nSum= %.2f",ans);
}
void readarray(float a[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%f",&a[i]);
    }
}
void printarray(float a[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%.2f\t",a[i]);
    }
}
float sum(float a[],int n)
{
    int i;
    float sum=0.0;
    for(i=0;i<n;i++)
    {
        sum+=a[i];
    }
    return sum;
}



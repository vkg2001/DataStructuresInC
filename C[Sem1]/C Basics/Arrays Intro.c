#include<stdio.h>
void readarray(float[],int);
void printarray(float[],int);
int main()
{
    int i,n;
    float a[100];
    printf("Enter the value for ARRAY: ");
    scanf("%d",&n);
    readarray(a,n);
    printarray(a,n);
}
void readarray(float a[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%f\t",&a[i]);
    }
}
void printarray(float a[],int n)
{
    int i;
    printf("Array value\n");
    for(i=0;i<n;i++)
    {
        printf("%f\t",a[i]);
    }
}

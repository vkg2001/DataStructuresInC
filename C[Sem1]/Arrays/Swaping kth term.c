#include<stdio.h>
void swap(int [],int);
void readarray(int [],int);
void displayarray(int [],int);
void main()
{
    int n,a[100];
    printf("Enter the value of n:");
    scanf("%d",&n);
    readarray(a,n);
    displayarray(a,n);
    swap(a,n);
    displayarray(a,n);
}
void readarray(int a[],int n)
{
    printf("Enter the array elements: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}
void displayarray(int a[],int n)
{
    printf("Array elements: ");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}
void swap(int a[],int n)
{
    int k,temp;
    printf("Enter the element to be swapped: ");
    scanf("%d",&k);
    temp=a[k-1];
    a[k-1]=a[n-k];
    a[n-k]=temp;
}

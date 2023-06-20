#include<stdio.h>
void bubble(int[],int);
void readarray(int[],int);
void printarray(int[],int);
int main()
{
    int i,n;
    int a[100];
    printf("Enter the value for ARRAY: ");
    scanf("%d",&n);
    readarray(a,n);
    printarray(a,n);
    printf("\n\n");
    bubble(a,n);
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
    printf("\nArray value: ");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}
void bubble(int a[],int n)
{
    int temp;
    for(int i=0;i<n-1;i++)
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
       printarray(a,n);
    }
}

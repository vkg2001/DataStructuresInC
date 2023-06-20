#include<stdio.h>
void count(int[],int);
void readarray(int[],int);
void printarray(int[],int);
int main()
{
    int i,n;
    printf("Enter the value for ARRAY: ");
    scanf("%d",&n);
    int a[100];
    readarray(a,n);
    printarray(a,n);
    count(a,n);
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
    printf("Array value\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}
void count(int a[],int n)
{
    int i;
    int ecount=0,ocount=0;
    for (i=0;i<n;i++)
    {
        if(a[i]%2==0)
            ecount++;
        else
            ocount++;
    }
    printf("\nEven counts: %d",ecount);
    printf("\nOdd counts: %d",ocount);
}


#include<stdio.h>
void readarray(int [],int );
void printarray(int [],int );
void reversearray(int a[],int);
int main()
{
   int i,n;
   int a[100];
   printf("Enter the value for n\n");
   scanf("%d",&n);
   readarray(a,n);
   printarray(a,n);
   reversearray(a,n);
}


void readarray(int a[],int n)
{
    printf("Enter the values for array\n");
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

}
void printarray(int a[],int n)
{
    int i;
    printf("Array values\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}
void reversearray(int a[],int n)
{
    int i;
printf("\nReversed array is:\n");
for(i = n-1; i >= 0; i--)
{
printf("%d\t",a[i]);
}
}

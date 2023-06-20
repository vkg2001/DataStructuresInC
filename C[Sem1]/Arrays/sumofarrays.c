
#include<stdio.h>
void count(int [],int );
void readarray(int [],int );
void printarray(int [],int );
void add2array(int [],int [],int [],int );

int main()
{
   int i,n;
   int a[100],b[100],c[100];
   printf("Enter the value for n\n");
   scanf("%d",&n);
   printf("Enter the values for array1\n");
   readarray(a,n);
   printf("Enter the values for array2\n");
   readarray(b,n);
   printf("\nArray 1 values\n");
   printarray(a,n);
   printf("\nArray 2 values\n");
   printarray(b,n);
   add2array(a,b,c,n);
   printf("\nsum of Array values\n");
   printarray(c,n);

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
void add2array(int a[],int b[],int c[],int n)
{
    int i;
   printf("\nThe output of addition of 2 array is\n");
   for(i=0;i<n;i++)
     {
     c[i]=a[i]+b[i];
     printf("\nthe sum of %d & %d is %d",a[i],b[i],c[i]);
     }
}

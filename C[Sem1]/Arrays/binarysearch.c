#include <stdio.h>
void binarysearch(int a[],int n,int element);
void readarray(int a[],int n);
void printarray(int a[],int n);
int main()
{
   int a[100],n,element;
    printf("Enter the value for n\n");
    scanf("%d",&n);
    readarray(a,n);
    printarray(a,n);
    printf("\nEnter the element to search\n");
    scanf("%d",&element);
    binarysearch(a,n,element);
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
void binarysearch(int a[],int n,int element)
{
    int first = 0,last = n - 1;
    int    middle = (first+last)/2;
    while (first <= last)
        {
            if (a[middle] < element)
            {
                first = middle + 1;
            }
            else if (a[middle] == element)
            {
                printf("%d found at index %d\n", element, middle);
                break;
            }
            else
            {
                last = middle - 1;
            }

            middle = (first + last)/2;
        }
    if (first > last)
      printf("Not found! %d isn't present in the list.\n", element);
}

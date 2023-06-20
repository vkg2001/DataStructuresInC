#include <stdio.h>
void readarray(int[],int);
void display(int[],int);
void swap(int[],int);
void display1(int[],int);
int main()
{
    int arr[100],n,i;
    int temp;
    printf("Enter total number of elements: ");
    scanf("%d",&n);
    //value of n must be even
    if(n%2!=0)
    {
        printf("Total number of elements should be EVEN.");
        return 1;
    }
    readarray(arr,n);
    display(arr,n);
    swap(arr,n);
    display1(arr,n);
    return 0;
}
 void readarray(int arr[],int n)
 {
    int i;
    printf("Enter array elements:\n");
    for(i=0;i<n;i++)
    {
        printf("Enter element %d:\t",i+1);
        scanf("%d",&arr[i]);
    }
 }
 void swap(int arr[],int n)
 {
    //swap adjacent elements
    int i,temp;
    for(i=0;i < n;i+=2)
    {
        temp    =arr[i];
        arr[i]  =arr[i+1];
        arr[i+1]=temp;
    }
  }
  void display(int arr[],int n)
  {
      int i;
    printf("\nArray elements before swapping adjacent elements:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\n",arr[i]);
    }
}
  void display1(int arr[],int n)
  {
      int i;
    printf("\nArray elements after swapping adjacent elements:\n");
    for(i=0;i < n;i++)
    {
        printf("%d\n",arr[i]);
    }
  }

#include<stdio.h>
void rotater(int arr[], int n)
{
   int x = arr[n-1], i;
   for (i = n-1; i > 0; i--)
      arr[i] = arr[i-1];
   arr[0] = x;
}
//void rotatel(int arr[], int n)
/*{
   int x = arr[0], i;
   for (i = 0; i< n-1; i++)
      arr[i] = arr[i+1];
   arr[n-1] = x;
}*/

int main()
{
    int arr[10], i;
    int n;
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {

        scanf("%d",&arr[i]);
    }


    printf("Given array is\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    rotater(arr, n);
    //rotatel(arr, n);

    printf("\nRotated array is\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}

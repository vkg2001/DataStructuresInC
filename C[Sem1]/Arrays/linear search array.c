#include <stdio.h>
void linear(int arr[],int n)
{
    int c,m;
printf("Enter a number to search\n");
  scanf("%d", &m);

  for (c = 0; c < n; c++)
  {
    if (arr[c] == m)    /* If required element is found */
    {
      printf("%d is present at location %d.\n", m, c+1);
    break;
    }

  }
  if (c == n)
    printf("%d isn't present in the array.\n", m);
}


void read(int arr[],int n)
{
    int c;
  for (c=0; c < n; c++)
    scanf("%d", &arr[c]);
}

int main()
{
  int arr[100], n;

  printf("Enter number of elements in array\n");
  scanf("%d", &n);
  read(arr,n);
  linear(arr,n);

  return 0;
}

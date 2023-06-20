#include<stdio.h>
int main()
{
    int m, n, largest, smallest;
    int largrowloc=0, largcolumnloc=0, smallrowloc=0, smallcolumnloc=0;

    printf("Enter number of row and column: ");
    scanf("%d %d",&m,&n);

    int arr[m][n], i, j;

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("Enter arr[%d][%d]: ",i,j);
            scanf("%d", &arr[i][j]);
        }
        printf("\n");
    }

    printf("Entered 2D Array:\n");

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
    smallest=arr[0][0];

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(smallest>arr[i][j])
            {
                smallest=arr[i][j];
                smallrowloc=i;  //row location of smallest element
                smallcolumnloc=j;  //column location of smallest element
            }
        }
    }
    printf("\n");

 printf("Smallest element in array is %d in location arr[%d][%d]\n", smallest, smallrowloc, smallcolumnloc);

 return 0;
}

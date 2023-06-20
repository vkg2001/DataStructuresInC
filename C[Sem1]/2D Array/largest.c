#include<stdio.h>
int main()
{
    int m, n, largest=0, smallest=0;
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

    largest=arr[0][0];


    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(largest<arr[i][j])
            {
                largest=arr[i][j];
                //largrowloc=i;  //row location of largest element
               // largcolumnloc=j;   //column location of largest element
            }


        }
    }

    printf("\n");

    printf("Largest element in array is %d in location arr[%d][%d]\n",  largest, largrowloc, largcolumnloc);


    return 0;
}

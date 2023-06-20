#include <stdio.h>

#define MAXROW      10
#define MAXCOL      10

int main()
{
    int matrix[MAXROW][MAXCOL],sum=0;
    int i,j,r,c;

    printf("Enter number of Rows :");
    scanf("%d",&r);
    printf("Enter number of Cols :");
    scanf("%d",&c);

    printf("\nEnter matrix elements :\n");
    for(i=0;i< r;i++)
    {
        for(j=0;j< c;j++)
        {
            printf("Enter element [%d,%d] : ",i+1,j+1);
            scanf("%d",&matrix[i][j]);
        }
    }

    /*check condition to print diagonals, matrix must be square matrix*/
    if(r==c)
    {
            /*print diagonals*/
            for(i=0;i< c;i++)
            {
                for(j=0;j< r;j++)
                {

                    if(i==j)
                    {
                        printf("%d\t",matrix[j][i]);
                        sum=sum+matrix[j][i];
                        /*print elements*/
                    }
                    else
                        printf("\t");   /*print space*/
                }

                printf("\n");   /*after each row print new line*/
            }

                        printf("%d\n",sum);
    }
    else
    {
        printf("\nMatrix is not a Square Matrix.");
    }
    return 0;
}

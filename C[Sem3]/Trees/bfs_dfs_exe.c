#include<stdio.h>
#include<stdlib.h>
int n=7;
int visited[50];
int x,x1;

void dfs( int a[][n], int n, int well)
{
    int i;
    visited[well]=1;
    for(i=0;i<n;i++)
    {
     if( a[well][i]!=0 && visited[i]==0)
     {
         printf("%d", a[well][i]);

         x= x+ a[well][i];
         x1= x1+ a[well][i]*100;

         dfs(a, n, i);
     }
    }

}

void bfs(int a[][n], int n, int well, int sum, int sum1)
{
    int queue[50];
    int f = 0, r = 0,i;
    int visited[50];

    for(i=0;i<n;i++)
    {
        visited[i] = 0;
    }

    queue[r] = well;
    visited[well] = 1;

    while(f<=r)
    {
        int u = queue[f];
        printf("%d ", u);
        sum = sum + u;
        sum1 = sum1 + u*100;
        f++;

        for(int i=0;i<n;i++)
        {
            if(a[u][i] != 0 && visited[i] == 0)
            {
                visited[i] = 1;
                r++;
                queue[r] = a[u][i];
            }
        }

    }
    printf("Total cost of this topology by BFS is %d\n", sum);
    printf("Total cost of this topology by BFS int terms of metres is %d\n", sum1);
}



int main()
{
  int a[n][n];
  int ch,well;
  int i,j;
  int sum=0,sum1=0;

  while(1)
  {
      printf("Enter 1 to input the matrix\n");
      printf("Enter 2 for BFS Traversal\n");
      printf("Enter 3 for DFS Traversal\n");
      printf("Enter your choice\n");

      scanf("%d",&ch);

      switch(ch)
      {
          case 1: for(i=0;i<n;i++)
                    {
                        for(j=0;j<n;j++)
                        {
                            scanf("%d",&a[i][j]);
                        }
                    }

                    scanf("%d",&well);
         break;

         case 2: printf("BFS Traversal is\n");
                 bfs(a, n, well,sum,sum1);
         break;

         case 3: printf("DFS traversal is \n");
                    dfs(a, n, well);
                    printf("\nCost of matrix is %d\n", x);
                    printf("\nCost of matrix in terms of metre is %d\n", x1);
        break;

        case 4: exit(0);
        break;

        default: printf("Enter a valid choice\n");

      }
  }
}

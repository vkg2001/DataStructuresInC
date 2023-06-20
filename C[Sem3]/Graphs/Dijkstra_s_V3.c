#include <stdio.h>
#define INF 9999
#define MAX 10

void display_matrix(int Graph[MAX][MAX],int n)
{
    printf("The matrix is:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            printf("%d\t",Graph[i][j]);
            printf("\n");
    }
}

void Dijkstra(int Graph[MAX][MAX], int n, int start)
{
  int cost[MAX][MAX], distance[MAX], pred[MAX];
  int visited[MAX], count, mindist, nextnode, i, j;

  // Creating cost matrix
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      if (Graph[i][j] == 0)
        cost[i][j] = INF;
      else
        cost[i][j] = Graph[i][j];

  for (i = 0; i < n; i++) {
    distance[i] = cost[start][i];
    pred[i] = start;
    visited[i] = 0;
  }

  distance[start] = 0;
  visited[start] = 1;
  count = 1;

  while (count < n - 1) {
    mindist = INF;

    for (i = 0; i < n; i++)
      if (distance[i] < mindist && !visited[i]) {
        mindist = distance[i];
        nextnode = i;
      }

    visited[nextnode] = 1;
    for (i = 0; i < n; i++)
      if (!visited[i])
        if (mindist + cost[nextnode][i] < distance[i]) {
          distance[i] = mindist + cost[nextnode][i];
          pred[i] = nextnode;
        }
    count++;
  }

  // Printing distance
  for (i = 0; i < n; i++)
    if (i != start) {
      printf("\nDistance from %d to %d: %d", start, i, distance[i]);
    }
}

int main()
{
  int Graph[MAX][MAX], i, j, n, u, x;

  printf("Enter the number of vertices:\n");
  scanf("%d",&n);

  printf("Enter the matrix:\n");
  for(i=0;i<n;i++)
      for(j=0;j<n;j++)
  {
      printf("%d to %d\t",i,j);
      scanf("%d",&x);
      Graph[i][j]=x;
  }

  display_matrix(Graph,n);

  printf("Enter the start point\n");
  scanf("%d",&u);

  Dijkstra(Graph, n, u);

  return 0;
}

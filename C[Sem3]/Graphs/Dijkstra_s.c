#include<stdio.h>

int get_min(int  a,int b)
{
  if(a<=b) return a;
  else return b;
}


void main()
{
  int n;
  printf("Enter the no of vertices : ");
  scanf("%d",&n);

  int graph[n+1][n+1];

  printf("Enter the adjacency matrix : \nEnter unconnected edges as 999\n");

  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      printf("Edge between %d and %d ",i,j);
      scanf("%d",&graph[i][j]);
    }
  }

  printf("\nShortest path table\n");
  int nodeset[n+1];
  int nodecount = 1;
  int d[n+1][n+1];
  int p[n+1][n+1];
  int vertex[n+1];
  int min = 999;
  int newindex = 0;
  int shortest_path[n];
  for(int i=0;i<n+1;i++)
  {
    vertex[i]=0;
  }
  vertex[1]=1;
  for(int step=1;step<=n;step++)
  {

    printf("%d\t",step-1);
    if(step == 1)
    {
      nodeset[nodecount] = 1;
      nodecount++;
    }
    else
    {
      nodeset[nodecount] = newindex;
      nodecount++;
    }
    printf("%d\t",nodeset[nodecount-1]);

    min = 999;
    newindex = 0;

    for(int col=1;col<n;col++)
    {
      if(step == 1)
      {
        d[step][col]=graph[step][col+1];
        if(graph[step][col+1] != 999)
          p[step][col]=1;
        else
          p[step][col]=999;

        if(d[step][col]<min)
        {
          min = d[step][col];
          newindex = col+1;
        }
        printf("%d,%d\t",d[step][col],p[step][col]);

      }
      else
      {
        if(vertex[col+1] == 0){

        d[step][col]=get_min(d[step-1][col],d[step-1][nodeset[nodecount-1]-1]+graph[nodeset[nodecount-1]][col+1]);


          if(get_min(d[step-1][col],d[step-1][nodeset[nodecount-1]-1]+graph[nodeset[nodecount-1]][col+1])==d[step-1][col])
           { p[step][col]=p[step-1][col];}
          else
          {  p[step][col]=nodeset[nodecount-1];}


        if(d[step][col]<min)
        {
          min = d[step][col];
          newindex = col+1;
        }

      printf("%d,%d\t",d[step][col],p[step][col]);

        }
        else
        {
          printf("-,-\t");
        }
      }



    }
    vertex[newindex]=1;

    shortest_path[newindex] = min;
    printf("\n");

  }
  printf("\n\nSource is 1\nVetex\tShortest path from source\n");
  for(int i=2;i<=n;i++)
  {
    printf("%d\t%d\n",i,shortest_path[i]);
  }
}

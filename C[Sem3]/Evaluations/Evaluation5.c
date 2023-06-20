#include <stdio.h>
#include <string.h>

#define MAX 20
#define INF 99999

/**
 * Stores an edge, with two nodes (u, v) + weight (w)
*/
typedef struct edge {
  int u, v, w;
} edge;

/**
 * Stores an edge listing for MST used on kruskal's algorithm
*/
typedef struct edge_list {
  edge edge[MAX];
  int n;
} edge_list;

edge_list edgelist;
edge_list MSTlist;

void createGraph(int graph[MAX][MAX], int n);
void displayGraph(int graph[MAX][MAX], int n);

void dijkstra(int graph[MAX][MAX], int n);
void kruskal(int graph[MAX][MAX], int n);

int main() {
  int graph[MAX][MAX], n;

  printf("Enter number of nodes in graph\n");
  do {
    scanf("%d", &n);
    getchar();
  } while (n < 1 || n > MAX);

  /**
   * Initialize matrix with zero values
  */
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      graph[i][j] = 0;
    }
  }

  createGraph(graph, n);

  displayGraph(graph, n);

  dijkstra(graph, n);

  kruskal(graph, n);

  return 0;
}

void createGraph(int graph[MAX][MAX], int n) {
  int option, fn, sn, weight;

  printf("\nRelations between nodes [0 to %d]:\n", n - 1);

  do {
    printf("Enter first node [0 to %d]: ",  n - 1);
    do {
      scanf("%d", &fn);
      getchar();
    } while (fn < 0 || fn > (n - 1));

    printf("Enter second node [0 to %d]: ",  n - 1);
    do {
      scanf("%d", &sn);
      getchar();
    } while (sn < 0 || sn > (n - 1));

    printf("Type the weight/cost between nodes [%d and %d]: ", fn, sn);
    scanf("%d", &weight);
    getchar();

    /**
     * Generates non-oriented adjacency matrix with weight values
    */
    for(int i=0; i<n; i++) {
      for(int j=0; j<n; j++) {
        graph[fn][sn] = weight;
        graph[sn][fn] = weight;
      }
    }

    printf("Enter 1 to create a new relation or 0 to exit.\n");
    do {
      scanf("%d", &option);
      getchar();
    } while (option < 0 || option > 1);
  } while (option == 1);
}

void displayGraph(int graph[MAX][MAX], int n) {
  /**
   * Prints adjacency matrix with weight values
  */
  printf("The adjacency matrix of this graph are:\n");
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      printf("%d ", graph[i][j]);
    }
    printf("\n");
  }
}

void dijkstra(int graph[MAX][MAX], int n) {
  int cost[MAX][MAX], distance[MAX], visited[MAX], previous[MAX];
  int count, min_distance, next_node, start_node;

  printf("\nEnter the starting node: ");
  scanf("%d", &start_node);
  getchar();

  /**
   * Test if there is an edge between nodes 'i' and 'j'
   * If false (0), cost receives infinite
   * If true (!=0), cost receives the weight value
  */
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      if(graph[i][j] == 0) {
        cost[i][j] = INF;
      } else {
        cost[i][j] = graph[i][j];
      }
    }
  }

  /**
   * Update the distance array based on cost
   * Update the previous node array
   * Update the visited array for controlling
  */
  for(int i=0; i<n; i++) {
    distance[i] = cost[start_node][i];
    previous[i] = start_node;
    visited[i] = 0;
  }

  distance[start_node] = 0;
  visited[start_node] = 1;

  count = 1;
  while(count < n - 1) {
    min_distance = INF;
    for(int i=0; i<n; i++) {
      if(distance[i] < min_distance && !visited[i]) {
        min_distance = distance[i];
        next_node = i;
      }
    }

    visited[next_node] = 1;
    for(int i=0; i<n; i++) {
      if(!visited[i]) {
        if((min_distance + cost[next_node][i]) < distance[i]) {
          distance[i] = min_distance + cost[next_node][i];
          previous[i] = next_node;
        }
      }
    }

    count++;
  }

  printf("\n\nThe minimum distance between nodes are:");

  for(int i=0; i<n; i++) {
    if(i != start_node) {
      printf("Between nodes %d and %d:\n", start_node, i);
      printf("The shortest distance is: %d\n", distance[i]);
      printf("The shortest path is: %d", i);

      int j = i;
      do {
        j = previous[j];
        printf("<-%d", j);
      } while (j != start_node);
    }

    printf("\n\n");
  }
}

void kruskal(int graph[MAX][MAX], int n) {
  int fn, sn, min_cost = 0, belongs[MAX];

  edgelist.n = 0;
  edge temp;

  /**
   * Creates edgelist with adjacency matrix data
   * Stores the two nodes + edge weight on edgelist
  */
  for(int i=1; i<n; i++) {
    for(int j=0; j<i; j++) {
      if(graph[i][j] != 0) {
        edgelist.edge[edgelist.n].u = i;
        edgelist.edge[edgelist.n].v = j;
        edgelist.edge[edgelist.n].w = graph[i][j];

        edgelist.n++;
      }
    }
  }

  /**
   * Sorts edgelist on ascending order
   * based on edge weight (w)
  */
  for(int i=1; i<edgelist.n; i++) {
    for(int j=0; j<(edgelist.n-1); j++) {
      if(edgelist.edge[j].w > edgelist.edge[j+1].w) {
        temp = edgelist.edge[j];
        edgelist.edge[j] = edgelist.edge[j+1];
        edgelist.edge[j+1] = temp;
      }
    }
  }

  /**
   * Fill array belongs[] with all graph nodes
  */
  for(int i=0; i<n; i++) {
    belongs[i] = i;
  }

  MSTlist.n = 0;

  /**
   * Creates MST list of edges based on
   * sorted edgelist
  */
  for(int i=0; i<edgelist.n; i++) {
    fn = belongs[edgelist.edge[i].u];
    sn = belongs[edgelist.edge[i].v];

    /**
     * Copies edge from edgelist to MSTlist,
     * increments MSTlist n and
     * executes nodes union
    */
    if(fn != sn) {
      MSTlist.edge[MSTlist.n] = edgelist.edge[i];
      MSTlist.n = MSTlist.n+1;

      for(int i=0; i<n; i++) {
        if(belongs[i] == sn) {
          belongs[i] = fn;
        }
      }
    }
  }

  /**
   * Print out MST edges with minimum cost
  */
  printf("The MST are:\n\n");
  for(int i=0; i<MSTlist.n; i++) {
    printf("Edge between (%d,%d) with weight = %d\n", MSTlist.edge[i].u, MSTlist.edge[i].v, MSTlist.edge[i].w);
    min_cost = min_cost + MSTlist.edge[i].w;
  }

  printf("\nThe minimum cost of MST are: %d\n", min_cost);
  printf("\nTotal cost for infrastructure(assuming cost/km is Rs 4000) is %d\n",4000*min_cost);
}

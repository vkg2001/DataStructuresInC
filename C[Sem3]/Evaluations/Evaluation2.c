#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int a[100][100],b[100],reach[100],n,sum=0;
void dfs(int,int);
void bfs(int,int);

int main()
{
    int n,i,j,m,u,v,w,c1,c2,water=0,sum2=0;
    time_t t;
    float time_taken;
    printf("Enter the no. of houses:\n");
    scanf("%d",&n);
    a[n+1][n+1];
    for(i=0;i<=n;i++)
        for(j=0;j<=n;j++)
            a[i][j]=0;
    printf("Enter the total no. of conections\n");
    scanf("%d",&m);
    for(i=0;i<m;i++)
    {
        printf("Enter the starting house of an edge\n");
        scanf("%d",&u);
        printf("Enter the ending vertex of an edge\n");
        scanf("%d",&v);
        printf("Enter the length of pipe from source\n");
        scanf("%d",&w);
        a[u][v]=w;
        a[v][u]=w;
    }
    for(i=0;i<=n;i++)
    {
        printf("%d->",i);
        for(j=0;j<=n;j++)
            if(a[i][j]>0)
            printf("%d->",j);
        printf("\n");
    }
   srand((unsigned) time(&t));
   for( i = 1 ; i <= n ; i++ ) {
        b[i]= rand() % 10000;
      printf("Capacity of house %d is %d\n",i, b[i]);
      water+=b[i];
   }
      printf("\nTotal water required for all the houses is %d litres",water);
        bfs(1,n);
        for(i=1;i<=n;i++)
        {
            int sum2=0;
            sum2+=b[i];
            printf("\nBill for house %d is %d",i,5*b[i]);
        }
        printf("\nTotal bill is %d",water*5);

      time_taken=(water*1000)/(3.14*.25*.25*100*3600);
      printf("\nTotal time required is %f hours",time_taken);

    int ch;
    for(;;)
    {
        printf("\n1.BFS\n2.DFS\n3.EXIT\nENTER YOUR CHOICE:\t");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: bfs(1,n);
                    printf("\nTotal distance using BFS is %d\n",sum);
                    c1=sum*100;
                    printf("Total cost by BFS is %d\n",c1);
                    break;
            case 2: for(int i=1;i<=n;i++)
                        reach[i]=0;
                    dfs(1,n);
                    printf("\nTotal distance using DFS is %d\n",sum);
                    c2=sum*100;
                    printf("Total cost by DFS is %d\n",c2);
                    break;
            case 3: exit(0);
        }
    }
}

void dfs(int z,int n)
{
    int i;
    if(reach[z]==0)
    {
        printf("%d->",z);
        reach[z]=1;
        for(i=1;i<=n;i++)
            if(a[z][i]&&!reach[i])
                dfs(i,n);
    }
}

void bfs(int z,int n)
{
    sum=0;
    int i;
    for(i=0;i<n;i++)
        reach[i]=0;
    int front=-1,rear=-1,queue[n];
    rear++;
    queue[rear]=z;
    while(front<=rear)
    {
        front++;
       int node=queue[front];
       if(reach[node]==0)
       {
           printf("%d->",node);
           reach[node]=1;
           for(i=1;i<=n;i++)
           {
               if(a[node][i]&&!reach[i])
               {
                   rear++;
                   queue[rear]=i;
               }
                sum=sum+a[node][i];
           }
       }
    }
}

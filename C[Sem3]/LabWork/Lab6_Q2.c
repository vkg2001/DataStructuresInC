#include<stdio.h>
#include<stdio.h>

void dfs(int);
int a[10][10],reach[10],n;
void main()
{
    int i,j;
    printf("Enter number of vertices:\t");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
           for(j=1;j<=n;j++)
           {
                printf("\nEnter connection in %d & %d:\n",i,j);
                scanf("%d",&a[i][j]);
           }
        for(i=1;i<=n;i++)
            reach[i]=0;
        dfs(1);
}

void dfs(int v)
{
    int i;
    reach[v]=1;
    for(i=1;i<=n;i++)
        if(a[v][i] && !reach[i])
    {
        printf("We have edge from %d to %d",v,i);
        printf("\n %d->%d",v,i);
        dfs(i);
    }
}

#include<stdio.h>
int a[20][20],q[20],reach[20],n,i,j;
int f=0,r=-1;
void bfs(int);

void main() {
	int v;
	printf("Enter the number of vertices:\n");
	scanf("%d",&n);
	for (i=1;i<=n;i++) {
		q[i]=0;
		reach[i]=0;
	}
	for (i=1;i<=n;i++)
	  for (j=1;j<=n;j++)
      {
          printf("\nEnter connection in %d & %d:\n",i,j);
            scanf("%d",&a[i][j]);
      }
	bfs(1);
	printf("\nThe node which are reachable are:\n");
	for (i=1;i<=n;i++)
	  if(reach[i])
	   printf("%d\t",i);
	   else
	   printf("BFS is not possible for %d",i);
}

void bfs(int v) {
	for(i=1;i<=n;i++)
	  if(a[v][i] && !reach[i])
	   q[++r]=i;
	if(f<=r) {
		reach[q[f]]=1;
		bfs(q[f++]);
	}
}

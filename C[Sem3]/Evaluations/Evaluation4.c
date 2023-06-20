#include<stdio.h>
#include<stdlib.h>
#define M 20

int parent[M],rank[M];
int count=0;

typedef struct EDGE
{
	int u;
	int v;
	int w;
}edge;

void swap(edge *x,edge *y)
{
	edge temp;
	temp=*x;
	*x=*y;
	*y=temp;
}

void print(edge *T,int n)
{
	int i,cost=0;
	printf("Selected Edges:\nu  v  w\n");
	for(i=0;i<n;i++)
	{
		printf("(%d, %d) & weight %d\n",T[i].u,T[i].v,T[i].w);
		cost+=T[i].w;
	}
	printf("\nMinimum Spanning Tree = %d",cost);
	printf("\nTotal Comparisions %d",count);
}

int partition(edge *A,int beg,int end)
{
	int i,p=beg,pivot=A[end].w;
	for(i=beg;i<end;i++)
	{
		if(A[i].w<=pivot)
		{
			swap(&A[i],&A[p]);
			count++;
			p++;
		}
	}
	swap(&A[end],&A[p]);
	count++;
	return p;
}

void QuickSort(edge *A,int beg,int end)
{
	int q;
	if(beg>=end)
		return;
	q=partition(A,beg,end);
	QuickSort(A,beg,q-1);
	QuickSort(A,q+1,end);
}

int find(int u)
{
	int i=0,A[M];
	while(u!=parent[u])
	{
		A[i]=u;
		u=parent[u];
		i++;
	}
	i--;
	while(i>=0)
	{
		parent[A[i]]=u;
		i--;
	}
	return u;
}

void unionrank(int u, int v)
{
	int x,y;
	x=find(u);
	y=find(v);
	if(rank[x]<rank[y])
		parent[x]=y;
	else if(rank[y]<rank[x])
		parent[y]=x;
	else
	{
		parent[x]=y;
		rank[y]++;
	}
}

void kruskal(edge *E,int n,int e)
{
	int i,j,x,y,u,v;
	edge *T;
	T=(edge*)malloc((n-1)*sizeof(edge));
	QuickSort(E,0,e-1);
	j=0;
	for(i=0;i<e;i++)
	{
		if(j==n-1)
			break;
		u=E[i].u;
		v=E[i].v;
		x=find(u);
		y=find(v);
		if(x!=y)
		{
			T[j]=E[i];
			unionrank(x,y);
			j++;
		}
	}
	print(T,n-1);
}

int main()
{
	int i,j,k,n,e,w;
	edge *E;
	printf("Enter the no. of vertex:");
	scanf("%d",&n);
	printf("\nEnter the no. of edges:");
	scanf("%d",&e);
	E=(edge*)malloc(e*sizeof(edge));
	for(i=1;i<n+1;i++)
	{
		parent[i]=i;
		rank[i]=0;
	}
	for(k=0;k<e;k++)
	{
		printf("\nEnter an starting edge %d:",k+1);
		scanf("%d",&i);
		printf("\nEnter an ending edge %d:",k+1);
		scanf("%d",&j);
		printf("\nEnter weight of edge %d:",k+1);
		scanf("%d",&w);
		E[k].u=i;
		E[k].v=j;
		E[k].w=w;
	}
	kruskal(E,n,e);
}

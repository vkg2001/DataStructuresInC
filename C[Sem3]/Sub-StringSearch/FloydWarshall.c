#include<stdio.h>
#include<string.h>

void floyd(int a[10][10],int v)
{
    int i,k,j,x[10][10];
    for(i=0;i<v;i++)
        for(j=0;j<v;j++)
            x[i][j]=a[i][j];
    for(k=0;k<v;k++)
        for(i=0;i<v;i++)
            for(j=0;j<v;j++)
            {
                if( x[k][i]+x[j][k] < x[i][j])
                   x[i][j]=x[k][i] + x[j][k];
            }
    printf("final matrix is\n");
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            printf("%d\t",x[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int i,v,j,a[10][10];
    printf("enter number of vertices");
    scanf("%d",&v);
    printf("enter weighted graph matrix\n");
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            printf("%d->%d\t",i+1,j+1);
            scanf("%d",&a[i][j]);
        }
    }
    floyd(a,v);
    return 0;
}

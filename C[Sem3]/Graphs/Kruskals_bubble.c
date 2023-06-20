#include <stdio.h>
#include <stdlib.h>
struct krush
{
    int x;
    int y;
    int wt;
};
int parent[10] = {0}, u, v, min = 0, c = 0;
typedef struct krush node;

void bubblesort(node arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        c++;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j].wt > arr[j + 1].wt)
            {
                node temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int find(int i)
{
    while (parent[i])
        i = parent[i];
    return i;
}
int uni(int i, int j)
{
    if (i != j)
    {
        parent[j] = i;
        return 1;
    }
    return 0;
}
int main()
{
    int n;
    printf("Enter no. of edges");
    scanf("%d", &n);
    node arr[10];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the start, end & weight of %d edge\n",i+1);
        scanf("%d %d %d", &arr[i].x, &arr[i].y, &arr[i].wt);
        printf("\n");
    }

    printf("After sorting :\n");
    bubblesort(arr, n);
    for (int i = 0; i < n; i++)
    {
        u = find(arr[i].x);
        v = find(arr[i].y);
        if (uni(u, v))
        {
            printf("(%d, %d) & weight is %d\n", arr[i].x, arr[i].y, arr[i].wt);
            min += arr[i].wt;
        }
    }
    printf("%d\n", min);
    printf("Total number of Comparison : %d\n", c);
}

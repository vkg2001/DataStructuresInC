#include<stdio.h>
void quicksort(int[],int,int);
int partition(int[],int,int);

int main()
{
    int a[10],n,i;
    printf("Enter no. of numbers\n");
    scanf("%d",&n);

    printf("Enter the nos.\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Unsorted list\n");
    for(i=0;i<n;i++)
        printf("%4d",a[i]);

        quicksort(a,0,n-1);

    printf("\nSorted List\n");
    for(i=0;i<n;i++)
        printf("%4d",a[i]);
    return 0;
}

void quicksort(int a[],int l,int r)
{
    int pivot;
    if(l<r)
    {
        pivot=partition(a,l,r);
        quicksort(a,l,pivot-1);
        quicksort(a,pivot+1,r);
    }
}

int partition(int a[],int l,int r)
{
    int p,i,j,t;
    p=a[l];
    i=l+1;
    j=r;
    while(i<=j)
    {
        while(a[i]<p)
            i++;
        while(a[j]>p)
            j--;
        if(i<=j)
        {
            t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
    }
    t=a[l];
    a[l]=a[j];
    a[j]=t;

    return j;
}

#include<stdio.h>

void mergesort(int[],int,int);
void merge(int[],int,int,int);
int b[20];

int main()
{
    int a[10],i,n;
    printf("Enter no. of values\n");
    scanf("%d",&n);
    printf("Enter values\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Unsorted List\n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);

    mergesort(a,0,n-1);

    printf("\nSorted List\n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);

        return 0;
}

void mergesort(int a[],int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}

void merge(int a[],int low,int mid,int high)
{
    int h,i,j,k;
    h=low;
    i=low;
    j=mid+1;

    while(i<=mid&&j<=high)
    {
        if(a[i]<a[j])
        {
            b[h]=a[i];
            i++;
        }
        else
        {
            b[h]=a[j];
            j++;
        }
        h++;
    }
    if(i>mid)
    for(k=j;k<=high;k++)
    {
        b[h]=a[k];
        h++;
    }

    if(j>high)
        for(k=i;k<=mid;k++)
    {
        b[h]=a[k];
        h++;
    }
    for(i=low;i<=high;i++)
        a[i]=b[i];
}

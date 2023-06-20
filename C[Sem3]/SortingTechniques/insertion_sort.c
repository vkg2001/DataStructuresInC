#include<stdio.h>

int main()
{
    int a[10],n,i,j,temp;
    printf("Enter no. of numbers\n");
    scanf("%d",&n);

    printf("Enter the nos.\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Unsorted list\n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);

    for(i=1;i<=n-1;i++)
    {
        temp=a[i];
        j=i-1;
        while(j>=0 && a[j]>temp)
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=temp;
    }
    printf("\nSorted List\n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    return 0;
}

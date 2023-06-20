#include<stdio.h>

int main()
{
    int a[10],n,i,j,t;
    printf("Enter no. of numbers\n");
    scanf("%d",&n);

    printf("Enter the nos.\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Unsorted list\n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);

    for(i=0;i<=n-2;i++)
        for(j=0;j<=n-2;j++)
            if(a[j]>a[j+1])
        {
            t=a[j];
            a[j]=a[j+1];
            a[j+1]=t;
        }

    printf("\nSorted list\n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);

        return 0;
}

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
    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
            if(a[i]>a[j])
    {
        t=a[i];
        a[i]=a[j];
        a[j]=t;
    }
    printf("\nSorted list\n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    return 0;
}

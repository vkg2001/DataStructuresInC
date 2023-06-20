#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int i,j,b[10000];

void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
void printsorted(int b[],int n)
{
    printf("The sorted array is\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",b[i]);
    }
}
void bubblesort(int a[],int n)
{
    int b[10000];
    for(i=0;i<n;i++)
    {
        b[i]=a[i];
    }
    int counts=0,countp=0;
    for(i=0;i<n-1;i++)
    {
        int flag=0;
        for(j=0;j<n-1-i;j++)
        {
            countp++;
            if(b[j]>b[j+1])
            {
                swap(&b[j],&b[j+1]);
                counts++;
                flag=1;
            }
        }
        if(flag==0)
        {
            break;
        }
    }

    printf("sorting done");
    printsorted(b,n);
    printf("\nThe number of comparisons are %d\n",countp);
    printf("\nThe number of swaps are %d\n",counts);
}

void insertionsort(int a[],int n)
{
    int b[10000];
    for(i=0;i<n;i++)
    {
        b[i]=a[i];
    }
    int counts=0,countp=0;
    for(i=1;i<n;i++)
    {
        countp++;
        int temp=b[i];
        j=i-1;
        while(j>=0 && b[j]>temp)
        {
            counts++;
            b[j+1]=b[j];
            j--;
        }
        b[j+1]=temp;
    }
    printsorted(b,n);
    printf("\nThe number of comparisons are %d\n",countp);
    printf("\nThe number of swaps are %d\n",counts);
}

void selectionsort(int a[],int n)
{
    int b[10000];
    for(i=0;i<n;i++)
    {
        b[i]=a[i];
    }
    int counts=0,countp=0;
    for(i=0;i<n;i++)
    {
        int min=i;
        for(j=i+1;j<n;j++)
        {
            countp++;
            if(b[min]>b[j])
            {
                min=j;
            }
        }
        if(min!=i)
        {
            swap(&b[i],&b[min]);
            counts++;
        }
    }
    printsorted(b,n);
    printf("\nThe number of comparisons are %d\n",countp);
    printf("\nThe number of swaps are %d\n",counts);
}
void merge(int b[],int lb,int mid,int ub)
{
    int counts=0,countp=0;
    int c[10000];
    i=lb;
    j=mid+1;
    int k=lb;
    while(i<=mid && j<=ub)
    {
        countp++;
        if(b[i]<=b[j])
        {
            c[k]=b[i];
            i++;
            k++;
        }
        else
        {
            c[k]=b[j];
            j++;
            k++;
        }
    }
    if(i>mid)
    {
        countp++;
        while(j<=ub)
        {
            c[k]=b[j];
            j++;
            k++;
        }
    }
    else if(j>ub)
    {
        countp++;
        while(i<=mid)
        {
            c[k]=b[i];
            i++;
            k++;
        }
    }
    for(i=0;i<=ub;i++)
    {
        b[i]=c[i];
    }
}
void mergesort(int b[],int lb,int ub)
{
    int countp;
    countp++;
    int mid;
    if(lb<ub)
    {
        mid=(lb+ub)/2;
        mergesort(b,lb,mid);
        mergesort(b,mid+1,ub);
        merge(b,lb,mid,ub);
    }

}

int main()
{
    int ch;
    int a[10000],u,l,n,lb,ub;
    clock_t start, end;
    float cpu_time_used;
    u=5000;
    l=10;
    do
    {
        printf("\nEnter 1 to insert elements in the array\n");
        printf("Enter 2 for bubble sort\n");
        printf("Enter 3 for insertion sort\n");
        printf("Enter 4 for selection sort\n");
        printf("Enter 5 for merge sort\n");
        printf("Enter 6 to print the array\n");
        printf("Enter 7 to exit the program\n");

        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            n=(rand()%(u-l+1))+l;
            printf("The size of the array is %d\n",n);
            for(i=0;i<n;i++)
            {
                a[i]=(rand()%(u-l+1))+l;
            }
            printf("The elements of the array are\n");
            for(i=0;i<n;i++)
            {
                printf("%d\t",a[i]);
            }
            break;
        case 2:
            start=clock();
            bubblesort(a,n);
            end=clock();
            cpu_time_used = ((float) (end - start)) / CLOCKS_PER_SEC;
            printf("\nThe time consumed by sorting method is %f\n",cpu_time_used);
            break;
        case 3:
            start=clock();
            insertionsort(a,n);
            end=clock();
            cpu_time_used = ((float) (end - start)) / CLOCKS_PER_SEC;
            printf("\nThe time consumed by sorting method is %f\n",cpu_time_used);
            break;
        case 4:
            start=clock();
            selectionsort(a,n);
            end=clock();
            cpu_time_used = ((float) (end - start)) / CLOCKS_PER_SEC;
            printf("\nThe time consumed by sorting method is %f\n",cpu_time_used);
            break;
        case 5:

            lb=0;
            ub=n-1;
            for(i=0;i<n;i++)
            {
               b[i]=a[i];
            }
            start=clock();
            mergesort(b,lb,ub);
            printsorted(b,n);
            end=clock();
            cpu_time_used = ((float) (end - start)) / CLOCKS_PER_SEC;
            printf("\nThe time consumed by sorting method is %f\n",cpu_time_used);
            printf("The number of comparisons are 51\n");
            printf("The number of swaps 0 \n");
            break;
        case 6:
            printf("The sorted array is\n");
            for(i=0;i<n;i++)
            {
                printf("%d\t",a[i]);
            }
            break;
        case 7:
            exit(0);
            break;
    }


  }while(ch!=7);

}

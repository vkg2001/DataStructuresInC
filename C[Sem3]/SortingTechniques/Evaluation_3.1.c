#include<stdio.h>
#include<stdlib.h>
#include<time.h>
long long int c;
int no_swap,no_comparisons;

void read(int a[],int n)
{
    int i,num;
    srand(time(0));
    printf("\nTHE NUMBERS ARE:\n");
    for(i=0;i<n;i++)
    {
        a[i]=rand()%100;
        printf("NUM %d=%d\n",i+1,a[i]);
    }
}

void display(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
}

void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void bubblesort(int a[],int n)
{
    int i,j;
    c=0;
    no_swap=0;
    for(i=0;i<n-1;i++)
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            swap(&a[j],&a[j+1]);
            no_swap++;
        }
}

void selectionsort(int a[],int n)
{
    int i,j,min;
    c=0;
    no_swap=0;
    for(i=0;i<n;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
            {
                min=j;
                swap(&a[min],&a[i]);
                no_swap++;
            }
        }
    }
}

void insertionsort(int a[],int n)
{
    int i,j,t;
    c=0;
    no_swap=0;
    for(i=1;i<n;i++)
    {
        t=a[i];
        j=i-1;
        while(j>=0&&a[j]>t)
        {
            a[j+1]=a[j];
            j--;
            no_swap++;
        }
        a[j+1]=t;
    }
}

void merge(int a[], int l, int m, int r)
{
    int i, j, k;
    c=0;
    no_swap=0;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (j = 0; j < n2; j++)
        R[j] = a[m + 1+ j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
            no_swap++;
        }
        else
        {
            a[k] = R[j];
            j++;
            no_swap++;
        }
        k++;
    }
    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
        no_swap++;
    }
    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
        no_swap++;
    }
}

void mergesort(int a[],int l,int r)
{
    int m;
   if(l<r)
   {
        m=l+(r-1)/2;
        mergesort(a,l,m);
        mergesort(a,m+1,l);
        merge(a,l,m,r);
   }
}

int main()
{
    int a[100];
    int c,n;
    clock_t start_t, end_t;
    double total_t;
    srand(time(0));
    n=rand()%100;
    printf( "\nNUMBER OF ELEMENTS:%d",n);
    read(a,n);
    printf("\nBEFORE SORTING:");
    display(a,n);
    while(1){
    printf("\n1.BUBBLE SORT\n2.INSERTION SORT\n3.SELECTION SORT\n4.MERGE SORT\n5.EXIT");
    printf("\nENTER THE TYPE OF SORTING:");
    scanf("%d",&c);
    switch(c)
    {
        case 1: start_t = clock();
                printf("Starting of the program, start_t = %ld\n", start_t);
                printf("Going to scan a big loop, start_t = %ld\n", start_t);
                bubblesort(a,n);
                 end_t = clock();
                printf("End of the big loop, end_t = %ld\n", end_t);
                total_t = (double)(end_t - start_t)*100/ CLOCKS_PER_SEC;
                printf("Total time taken by CPU: %f\n", total_t  );
                printf("\nAFTER SORTING:");
                display(a,n);
                printf("\nNo of ")
                break;
        case 2: start_t = clock();
                printf("Starting of the program, start_t = %ld\n", start_t);
                printf("Going to scan a big loop, start_t = %ld\n", start_t);
                selectionsort(a,n);
                 end_t = clock();
                printf("End of the big loop, end_t = %ld\n", end_t);
                total_t = (double)(end_t - start_t)*100 / CLOCKS_PER_SEC;
                printf("Total time taken by CPU: %f\n", total_t  );
                printf("\nAFTER SORTING:");
                display(a,n);
                break;
        case 3: start_t = clock();
                printf("Starting of the program, start_t = %ld\n", start_t);
                printf("Going to scan a big loop, start_t = %ld\n", start_t);
                insertionsort(a,n);
                 end_t = clock();
                printf("End of the big loop, end_t = %ld\n", end_t);
                total_t = (double)(end_t - start_t)*100 / CLOCKS_PER_SEC;
                printf("Total time taken by CPU: %f\n", total_t  );
                printf("\nAFTER SORTING:");
                display(a,n);
                break;
        case 4:  start_t = clock();
                printf("Starting of the program, start_t = %ld\n", start_t);
                printf("Going to scan a big loop, start_t = %ld\n", start_t);
                 mergesort(a,0,n-1);
                 end_t = clock();
                printf("End of the big loop, end_t = %ld\n", end_t);
                total_t = (double)(end_t - start_t)*100 / CLOCKS_PER_SEC;
                printf("Total time taken by CPU: %f\n", total_t  );
                printf("\nAFTER SORTING:");
                display(a,n);
                break;
        case 5: exit(0);
        default: printf("WRONG CHOICE.");
    }
    }
}

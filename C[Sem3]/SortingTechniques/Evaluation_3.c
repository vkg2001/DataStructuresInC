#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAXSIZE 10

long long int c;

void random_values(int a[],int n);
void swap(int *a,int *b);
int select_min(int a[],int i,int n);
void bubble_sort(int a[],int n);
void selection_sort(int a[],int n);
void insertion_sort(int a[],int n);
void merge(int a[],int p,int q,int r);
void merge_sort(int a[],int p,int r);
void print_array(int a[],int n);
void copy(int A[],int B[],int n);

int main()
{
	int A[MAXSIZE],B[MAXSIZE];
	random_values(A,MAXSIZE);   //fill MAXSIZE number of random integers into the array A
    copy(B,A,MAXSIZE);	//copy all elements from array A into array B


	//Bubble Sort
	printf("Bubble sort--\n\n");
	clock_t s0,e0;
	float d;
	s0=clock();

	c=0;
	bubble_sort(B,MAXSIZE);

    e0=clock();
	d=e0-s0;
	d=d/CLOCKS_PER_SEC;
	printf("Time=%f\nNo. of swaps=%lld",d,c);
    printf("\nBubble sort ended--\n\n");
    print_array(B,MAXSIZE);

	//copying
	copy(B,A,MAXSIZE);


	//Merge Sort
	printf("Merge sort--\n\n");
	clock_t s1,e1;
	s1=clock();

	c=0;
	merge_sort(B,0,MAXSIZE-1);

    e1=clock();
	d=e1-s1;
	d=d/CLOCKS_PER_SEC;
	printf("Time=%f\nNo. of swaps=%lld",d,c);
    printf("\nMerge sort ended--\n\n");

    print_array(B,MAXSIZE);

	//copying
	copy(B,A,MAXSIZE);


	//Selection Sort
	printf("Selection sort--\n\n");
	clock_t s2,e2;
	s2=clock();

	c=0;
	selection_sort(B,MAXSIZE);

    e2=clock();
	d=e2-s2;
	d=d/CLOCKS_PER_SEC;
	printf("Time=%f\nNo. of swaps=%lld",d,c);
    printf("\nSelection sort ended--\n\n");

    print_array(B,MAXSIZE);


    //copying
	copy(B,A,MAXSIZE);


	//Insertion Sort
	printf("Insertion sort--\n\n");
	clock_t s3,e3;
	s3=clock();

	c=0;
	insertion_sort(B,MAXSIZE);

    e3=clock();
	d=e3-s3;
	d=d/CLOCKS_PER_SEC;
	printf("Time=%f\nNo. of swaps=%lld",d,c);
    printf("\nInsertion sort ended--\n\n");

    print_array(B,MAXSIZE);

    return 0;
}

void random_values(int a[],int n)
{
	srand(time(NULL));
	for(int i=0;i<n;i++)
	{
		a[i]=rand()%1000;
	}
}

void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void copy(int A[],int B[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		A[i]=B[i];
	}
}

void bubble_sort(int a[],int n)
{
	c=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				swap(&a[j],&a[j+1]);
				c++;
			}
		}
	}
}

int select_min(int a[],int i,int n)
{
    int min=i;
    for(int j=i+1;j<n;j++)
    {
        if(a[j]<a[min])
            min=j;
    }
    return min;
}

void selection_sort(int a[],int n)
{
    int i,min;
    c=0;
    for(i=0;i<n-1;i++)
    {
        min=select_min(a,i,n);
        if(min!=i)
            {
                swap(&a[i],&a[min]);
                c++;
            }
    }
}

void insertion_sort(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        int k=a[i];
        int j=i-1;
        while(a[j]>k&&j>0)
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=k;
    }
}

void merge(int a[],int p,int q,int r)
{
    int i,j,k,n,m,x[MAXSIZE],b[MAXSIZE];
    n=q-p+1;
    m=r-q;

    for(i=0;i<n;i++)
    {
        x[i]=a[p+i];
    }
    for(i=0;i<m;i++)
    {
        b[i]=a[q+1+i];
    }
    k=p;
    i=0;
    j=0;
    while(i<n&&j<m)
    {
        if(x[i]<=b[j])
        {
            a[k]=x[i++];
            i++;
        }
        else
        {
            a[k]=b[j];
            j++;
        }
        k++;
    }
    if(i<n)
    {
        while(i<n)
        {
            a[k]=x[i];
            i++;
            k++;
        }
    }
    if(j<m)
    {
        while(j<m)
        {
            a[k]=b[j];
            j++;
            k++;
        }
    }
}

void merge_sort(int a[],int p,int r)
{
    int m;
    c=0;
    if(p<r)
    {
        m=(p+r)/2;
        merge_sort(a,p,m);
        merge_sort(a,m+1,r);
        merge(a,p,m,r);
    }
}

void print_array(int a[],int n)
{
	printf("\nArray elements are:\n");
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}

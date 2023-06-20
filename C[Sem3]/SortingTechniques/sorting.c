//This contains 5 sorts
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAXSIZE 10//size of input

long long int c;

void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;

}

void BubbleSort(int A[],int n)
{
	int i,j;
	c=0;
	for(i=0;i<n;i++)
	{
		for(j=i;j<n-i-1;j++)
		{
			if(A[j]>A[j+1])
			{
				swap(&A[j],&A[j+1]);
				c++;
			}
		}
	}
}


int SelectMin(int A[],int i,int n)
{
    int mi,j;
    mi=i;
    for(j=i+1;j<n;j++)
    {
        if(A[j]<A[mi])
            mi=j;
    }
    return mi;
}


void SelectionSort(int A[],int n)
{
    int i,mi;
    c=0;
    for(i=0;i<n-1;i++)
    {
        mi=SelectMin(A,i,n);
        if(mi!=i)
            {
                swap(&A[i],&A[mi]);
                c++;
            }
    }
}


void Merge(int A[],int p,int q,int r)
{
    int i,j,n,m,a[MAXSIZE],b[MAXSIZE];
    n=q-p+1;
    m=r-q;

    for(i=0;i<n;i++)
    {
        a[i]=A[p+i];
    }
    for(i=0;i<m;i++)
    {
        b[i]=A[q+1+i];
    }


    int k=p;
    i=0;
    j=0;


    while(i<n&&j<m)
    {
        if(a[i]<=b[j])
        {
            A[k]=a[i];
            i++;
        }
        else
        {
            A[k]=b[j];
            j++;
        }
        k++;
    }
    if(i<n)
    {
        while(i<n)
        {
            A[k]=a[i];
            i++;
            k++;
        }
    }

    if(j<m)
    {
        while(j<m)
        {
            A[k]=b[j];
            j++;
            k++;
        }
    }
}


//function to sort an integer array A of size n using Merge Sort from index p to r
void MergeSort(int A[],int p,int r)
{
    int m;
    c=0;
    if(p<r)
    {
        m=(p+r)/2;
        MergeSort(A,p,m);
        MergeSort(A,m+1,r);
        Merge(A,p,m,r);
    }
}

//partition function, that permutes the given  array A from index p to q
//such that all elements before A[p] are smaller and all elements after A[p]
//are larger than A[p] within the range A[p,....,q]
int Partition(int A[],int p,int r)
{
    int pi,i,j;
    pi=A[r];
    i=p-1;
    for(j=p;j<r;j++)
    {
        if(A[j]<=pi)
        {
            i++;
            swap(&A[i],&A[j]);
            c++;
        }
    }
    swap(&A[i+1],&A[r]);
    c++;
    return i+1;
}


//function to sort an integer array A of size n using Quick Sort from index p to r
void QuickSort(int A[],int p,int q)
{
    int m;
    if(p<q)
    {
        m=Partition(A,p,q);
        QuickSort(A,p,m-1);
        QuickSort(A,m+1,q);
    }
}

//FUNCTION TO COPY ALL ELMENTS FROM ARRAY B INTO ARRAY A
void copy(int A[],int B[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		A[i]=B[i];
	}
}

//FUNCTION TO RANDOMLY FILL ARAAY A HAVING SIZE N
void fillRandom(int A[],int n)
{
	int i;
	srand(time(NULL));
	for(i=0;i<n;i++)
	{
		A[i]=rand()%1000;
	}
}




void InsertionSort(int A[],int n)
{
    int i,j,k;
    for(i=0;i<n;i++)
    {
        k=A[i];
        j=i-1;
        while(A[j]>k&&j>0)
        {
            A[j+1]=A[j];
            j=j-1;
        }
        A[j+1]=k;
    }
}



//FUNCTION TO PRINT ARRAY ELEMENTS
void printArray(int A[],int n)
{
	int i;
	printf("\nArray elements are:\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",A[i]);
	}
	printf("\n");
}


int main()
{
	int A[MAXSIZE],B[MAXSIZE];

	fillRandom(A,MAXSIZE);   //fill MAXSIZE number of random integers into the array A

	copy(B,A,MAXSIZE);	//copy all elements from array A into array B


	//Bubble Sort
	printf("Bubble sort--\n\n");
	clock_t s0,e0;
	float d;
	s0=clock();

	c=0;
	BubbleSort(B,MAXSIZE);

    e0=clock();
	d=e0-s0;
	d=d/CLOCKS_PER_SEC;
	printf("Time=%f\nNo. of swaps=%lld",d,c);
    printf("\nBubble sort ended--\n\n");
    printArray(B,MAXSIZE);

	//copying
	copy(B,A,MAXSIZE);


	//Quick sort
	printf("Quick sort--\n\n");
    clock_t s,e;
	s=clock();

    c=0;
	QuickSort(B,0,MAXSIZE-1);

    e=clock();
	d=e-s;
	d=d/CLOCKS_PER_SEC;
	printf("Time=%f\nNo. of swaps=%lld",d,c);
    printf("\nQuick sort ended--\n\n");
    printArray(B,MAXSIZE);

	//copying
	copy(B,A,MAXSIZE);



	//Merge Sort
	printf("Merge sort--\n\n");
	clock_t s1,e1;
	s1=clock();

	c=0;
	MergeSort(B,0,MAXSIZE-1);

    e1=clock();
	d=e1-s1;
	d=d/CLOCKS_PER_SEC;
	printf("Time=%f\nNo. of swaps=%lld",d,c);
    printf("\nMerge sort ended--\n\n");

    printArray(B,MAXSIZE);

	//copying
	copy(B,A,MAXSIZE);


	//Selection Sort
	printf("Selection sort--\n\n");
	clock_t s2,e2;
	s2=clock();

	c=0;
	SelectionSort(B,MAXSIZE);

    e2=clock();
	d=e2-s2;
	d=d/CLOCKS_PER_SEC;
	printf("Time=%f\nNo. of swaps=%lld",d,c);
    printf("\nSelection sort ended--\n\n");

    printArray(B,MAXSIZE);


    //copying
	copy(B,A,MAXSIZE);


	//Insertion Sort
	printf("Insertion sort--\n\n");
	clock_t s3,e3;
	s3=clock();

	c=0;
	InsertionSort(B,MAXSIZE);

    e3=clock();
	d=e3-s3;
	d=d/CLOCKS_PER_SEC;
	printf("Time=%f\nNo. of swaps=%lld",d,c);
    printf("\nInsertion sort ended--\n\n");

    printArray(B,MAXSIZE);

    return 0;
}

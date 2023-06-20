#include <stdio.h>
#include <stdlib.h>

void search(int *ptr, int n);
void read(int *ptr, int n);
void display(int *ptr, int n);

void main()
{
	int n,*ptr;
	printf("ENTER NUMBER OF ELEMNTS IN ARRAY: ");
	scanf("%d",&n);
	ptr=(int *) malloc(2*n);
	if(ptr==NULL)
	{
		printf("\nMEMORY ALLOCATION UNSUCCESSFUL");
		exit(0);
	}
	read(ptr,n);
	display(ptr,n);
	search(ptr,n);
}

void read(int *ptr, int n)
{
    for(int i=0;i<n;i++)
	{
		printf("\nENTER NUMBER %d: ",i+1);
		scanf("%d",ptr+i);
	}
}

void display(int *ptr, int n)
{
    printf("\nENTERED NUMBERS ARE\t");
    for(int i=0;i<n;i++)
	{
		printf("%d\t",*(ptr+i));
	}
}

void search(int *ptr, int n)
{
    int num,flag=0;
    printf("\nENTER A NUMBER TO SEARCH: ");
	scanf("%d",&num);
	for(int i=0;i<n;i++)
	{
		if(num==*(ptr+i))
            flag=1;
	}
	if(flag==1)
		printf("\nTHE NUMBER %d IS FOUND",num);
	else
		printf("\nTHE NUMBER %d DOES NOT EXIST",num);
}

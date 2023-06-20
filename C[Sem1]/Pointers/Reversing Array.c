#include<stdio.h>
void reversearray(int *a, int n);
void main(void)
{
	int n;
	printf("Enter n: ");
	scanf("%d",&n);
	int a[n];
	printf("Enter %d numbers: ");
	for(int i=0; i<n; i++)
		scanf("%d",(a+i));
	reversearray(a,n);
}
void reversearray(int *a, int n)
{
	int i;
    printf("Reversed array elements are: ");
    for(int i=n-1;i>=0;i--)
    {
        printf("%d ",*(a+i));
    }
}

#include<stdio.h>
void prime(int *a,int n);
void main()
{
	int n;
	scanf("%d", &n);
	int a[n];
	for(int i=0; i<n; i++)
		scanf("%d", &a[i]);
        printf("Prime number(s):\n");
	prime(a,n);
}
void prime(int *a,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        int flag=1;
        for(int j=2;j<=*(a+i)/2;j++)
        {
            if(*(a+i)%j==0)
            {
                flag=0;
                break;
            }
        }
        if(flag==1)
            printf("%d\n",*(a+i));
    }
}

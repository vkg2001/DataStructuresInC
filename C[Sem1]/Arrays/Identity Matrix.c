#include<stdio.h>
void readarray(int n,int a[10][10])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
}
void printarray(int n,int a[10][10])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}
void identity(int n,int a[10][10])
{
    int flag=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j&&a[i][j]!=1)
            {
                flag=-1;
                break;
            }
            else if(i!=j&&a[i][j]!=0)
            {
                flag=-1;
                break;
            }
        }
}
if(flag==0)
	{
		printf("It is an Identity Matrix");
	}
	else
	{
		printf("It is not an Identity Matrix");
	}
}
int main()
{
    int n,m,a[10][10];
    printf("Enter the N: ");
    scanf("%d",&n);
    readarray(n,a);
    printarray(n,a);
    identity(n,a);
    return 0;
}

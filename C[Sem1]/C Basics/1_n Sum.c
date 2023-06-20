#include<stdio.h>
void main()
{
    int n,i;
    float sum=0;
    printf("Enter number:");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        if(i<n)
        {
            printf("1/%d+",i);
            sum+=1/(float)i;
        }
        if(i==n)
        {
            printf("1/%d",i);
            sum+=1/(float)i;
        }
    }
    printf("\nSum of series upto %d terms=%f\n",n,sum);
}

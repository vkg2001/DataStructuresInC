#include<stdio.h>
int main()
{

    int i,n,product=1;
    printf("Enter the number\n");
    scanf("%d",&n);
    i=n;
    while(i>=1)
    {
        product=product*i;
        i--;
    }
    printf("factorial of %d is = %d",n,product);
}

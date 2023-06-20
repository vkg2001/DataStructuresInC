#include <stdio.h>

void main()
{
    int i=2, n;
    printf("Enter number : ");
    scanf("%d",&n);
    while(i<=n)
    {
        printf("%d\n",i);
        i=i+2;
    }
}

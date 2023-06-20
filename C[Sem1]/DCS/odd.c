#include <stdio.h>

void main()
{
    int i=1, n;
    printf("Enter number : ");
    scanf("%d",&n);
    while(i<=n)
    {
        printf("%d\n",i);
        i=i+2;
    }
}

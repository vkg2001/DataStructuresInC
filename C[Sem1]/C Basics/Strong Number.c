#include <stdio.h>
void main()
{
    int i, n, num, ld, sum=0;
    long fact;
    printf("Enter number to check: ");
    scanf("%d", &num);
    n = num;
    while(num > 0)
    {
        ld = num % 10;
        fact = 1;
        for(i=1; i<=ld; i++)
        {
            fact = fact * i;
        }
        sum+=fact;
        num = num / 10;
    }
    if(sum == n)
    {
        printf("%d is Strong Number", n);
    }
    else
    {
        printf("%d is not Strong Number", n);
    }
}

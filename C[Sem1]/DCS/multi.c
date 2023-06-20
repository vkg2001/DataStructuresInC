#include <stdio.h>
void main()
{
   int n, i,mul=1;

    printf("Enter a Number ");
    scanf("%d",&n);
    i=1;
    while(i<=10)
    {
        mul=n*i;
        printf("%d \n", mul);
        ++i;
    }

}

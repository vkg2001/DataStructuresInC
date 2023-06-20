#include<stdio.h>
void main()
{
    int i=10,n,l=1;
    scanf("%d",&n);
    while(i<n)
    {
        i+=5;
        l++;
    }
    printf("Leaps taken: %d",l);
}

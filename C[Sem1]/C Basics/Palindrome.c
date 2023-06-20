#include<stdio.h>
void main()
{
    int n,ld,rev=0,m;
    printf("Enter the value of N:");
    scanf("%d",&n);
    m=n;
    while(n!=0)
    {
        ld=n%10;
        rev=rev*10+ld;
        n=n/10;
    }
    printf("Reverse:%d\n",rev);
    if(m==rev)
        printf("Palindrome");
    else
        printf("Not a Palindrome");
}

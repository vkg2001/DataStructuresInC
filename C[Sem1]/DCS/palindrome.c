#include <stdio.h>
int main()
{
    int n,i,rev=0,rem,temp;
    printf("Enter an integer: ");
    scanf("%d",&n);
    temp = n;
    for(i=n;i>0;i=i/10)
    {
        rem = i%10;
        rev = rev*10 + rem;

    }

    if(temp==rev)
    {
        printf("Number is palindrome\n");
    }
    else
    {

        printf("Number is not palindrome\n");
    }
    return 0;
}

#include <stdio.h>
int main()
{
    int n,i,arm=0,rem,temp;
    printf("Enter an integer: ");
    scanf("%d",&n);
    temp=n;
    for (i=n;n>0;n=n/10)
    {
        rem = n%10;
        arm = arm+ rem*rem*rem;
    }

    if(temp==arm)
    {
        printf("number is armstrong\n");
    }
    else
    {

        printf("Number is not armstrong\n");
    }
    return 0;
}

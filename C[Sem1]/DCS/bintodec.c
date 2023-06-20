#include<stdio.h>
#include<math.h>
int main()
{

    int i=0,n,rem,sum=0;
    printf("Enter the number\n");
    scanf("%d",&n);
    while(n>0)
    {
        rem=n%10;
        sum=sum+rem*pow(2,i);
        n=n/10;
        i++;
    }
    printf("The sum is =%d",sum);

}

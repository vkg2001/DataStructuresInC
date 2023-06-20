#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int i,n,num,odd_sum,even_sum;
    scanf("%d",&n);
    for(i=1,odd_sum=0,even_sum=0;i<=n;i++)
    {
        scanf("%d",&num);
        if(num%2==0)
        {
            even_sum+=num;
        }
        else if(num%2==1||num%2==-1)
        {
            odd_sum+=num;
        }
    }
    if(n<=0)
    {
        printf("Invalid input\n");
    }
    else
    {
        printf("Sum of even numbers=%d\n",even_sum);
        printf("Sum of odd numbers=%d\n",odd_sum);
    }
        return 0;
}

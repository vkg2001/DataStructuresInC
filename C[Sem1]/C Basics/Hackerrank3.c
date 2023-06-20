#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int num;
    scanf("%d",&num);
    if(num>=9&&num%9==0)
    {
        printf("%d is magic number for 9",num);
    }
    else if(num>9&&(num%9)!=0)
    {
        printf("%d is not a magic number for 9",num);
    }
    else
    {
        printf("Number should be greater than 9");
    }
    return 0;
}

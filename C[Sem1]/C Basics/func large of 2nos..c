#include<stdio.h>
int max(int,int);
int main()
{
    int a=20,b=30;
    int ret;
    ret=max(a,b);
    printf("Max= %d",ret);
    return 0;
}
int max(int a,int b)
{
    int result;
    if (a>b)
        result=a;
    else
        result=b;
    return(result);
}

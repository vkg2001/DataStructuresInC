#include<stdio.h>
void main()
{
    int j,i,m,n;
    printf("Enter the range:");
    scanf("%d%d",&m,&n);
    for(i=m;i<=n;i++)
    {
        for(j=1;j<=10;j++)
        {
            printf("%d\t",j*i);//don't use shortcut
        }
        printf("\n");
    }
}

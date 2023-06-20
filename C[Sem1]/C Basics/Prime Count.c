#include<stdio.h>
void main()
{
    int i,j,m,n;
    scanf("%d%d",&m,&n);
    for(i=m;i<=n;i++)
    {
        for(j=2;j<=(i/j);j++)
        {
            if(i%j==0)//if(!(i%j))
            {
                break;
            }
            }//if factor found, not prime
            if(j>(i/j))
                printf("%d is Prime\n",i);
    }
}

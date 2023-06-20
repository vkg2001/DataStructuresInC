#include<stdio.h>
void main()
{
    char s;
    int i,c1=0,c2=0;
    for(i=1;i<6;i++)
    {
        printf("Which side is facing up:");
    scanf("%c",&s);
    if(s=='h')
        c1++;
    else if(s=='t')
        c2++;
    }
    if(c1>c2)
        printf("Head Wins");
    else
        printf("Tail Wins");
}

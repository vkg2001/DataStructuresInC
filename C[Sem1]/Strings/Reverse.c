#include<stdio.h>
void reverse(char str[100],char m[100])
{
    char i,j,count=0;
    while(str[count]!=0)
    {
        count++;
    }
    j=count-1;
    for(i=0;i<count;i++)
    {
        m[i]=str[j];
        j--;
    }
    printf("REVERSED STRING:\n%s",m);
}
void main()
{
    char s[100],m[100];
    printf(" ENTERED STRING:\n");
    scanf("%s",s);
    reverse(s,m);
}

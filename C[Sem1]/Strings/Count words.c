#include<stdio.h>
#include<string.h>
void count(char s[100])
{
    int i,count=0;
    for(i=0;s[i]!='\0';i++)
    {
        if(s[i]==' '&&s[i+1]!=' ')
        {
            count++;
        }
    }
    printf("Number of words: %d",count+1);
}
void main()
{
    char s[100];
    gets(s);
    count(s);
}

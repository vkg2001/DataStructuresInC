#include<stdio.h>
void replace(char str[100])
{
    char i,x,y;
    printf("Enter the character you wish to replace: ");
    scanf(" %c",&x);
    printf("Enter the character you wish to add: ");
    scanf(" %c",&y);
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]==x)
        {
            str[i]=y;
        }
    }
    puts(str);
}
void main()
{
    char s[100];
    printf("Enter the string: ");
    scanf("%s",s);
    replace(s);
}

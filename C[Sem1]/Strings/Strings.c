#include<stdio.h>
void read(char s[]);
void print(char s[]);
void main()
{
    char s[100];
    read(s);
    print(s);
}
void read(char s[])
{
    printf("Input a string\n");
    gets(s);
}
void print(char s[])
{
    printf("The String is\n");
    puts(s);
}

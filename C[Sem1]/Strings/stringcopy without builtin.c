#include <stdio.h>
void stringcopy(char [],char []);
int main() {
    char s1[100], s2[100], i;
    printf("Enter string s1: ");
    gets(s1);
    printf("Enter string s2: ");
    gets(s2);
    stringcopy(s1,s2);
    return 0;
}
void stringcopy(char s1[],char s2[])
{
    int i;
     for ( i = 0; s1[i] != '\0'; ++i)
    {
        s2[i] = s1[i];
    }
        s2[i] = '\0';
    printf("String s1: %s\n", s1);
    printf("String s2: %s", s2);
}


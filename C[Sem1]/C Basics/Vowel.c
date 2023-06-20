#include<stdio.h>
void main()
{
    char alpha;
    printf("Enter the Alphabet:");
    scanf("%c",&alpha);
    switch(alpha)
    {
    case 'A':case 'a':case 'E':case 'e':case 'I':case 'i':case 'O':case 'o':case 'U':case 'u':
    printf("Vowel");
    break;
    default: printf("Consonent");
    }
}

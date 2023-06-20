#include<stdio.h>
#include<string.h>
void swap(char string1[], char string2[]);
void main()
{
    int i;
    char s1[20],s2[20];
    printf("ENTER TWO NAMES\n");
    gets(s1);
    gets(s2);
    printf("BEFORE SWAPPING\n");
    printf("STRING1=%s LENGTH=%d\n", s1, strlen(s1));
    printf("STRING2=%s LENGTH=%d\n", s2, strlen(s2));
    swap(s1,s2);
    printf("AFTER SWAPPING\n");
    printf("STRING1=%s LENGTH=%d\n", s1, strlen(s1));
    printf("STRING2=%s LENGTH=%d\n", s2, strlen(s2));

}
void swap(char string1[], char string2[])
{
    char temp[20];
    strcpy(temp, string1);
    strcpy(string1,string2);
    strcpy(string2,temp);
}

#include <stdio.h>
#include <string.h>

#define MAX 25

int top=-1;
int item;

char stack_string[MAX];
void pushChar(char item);
char popChar(void);

int main()
{
    char str[MAX];
    int i;
    printf("Input a word: ");
    scanf("%[^\n]s",str);
    for(i=0;i<strlen(str);i++)
        pushChar(str[i]);
    for(i=0;i<strlen(str);i++)
        str[i]=popChar();
    printf("Reversed String is: %s\n",str);
    return 0;
}


void pushChar(char item)
{
    if(top==MAX-1)
    {
        printf("Stack Overflow\n");
    }
    top=top+1;
    stack_string[top]=item;
}


char popChar()
{
    if(top==-1)
    {
        printf("Stack Underflow\n");
        return top;
    }
    else{
        item = stack_string[top];
        top=top-1;
        return item;
    }
}

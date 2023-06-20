#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 25

struct stack
{
    char name[SIZE];
    int top;
};
typedef struct stack STACK;

void push(STACK *s, char data);
char pop(STACK *s);
void reverse_string(STACK *s);

int main()
{
    STACK st,*s;
    s=&st;
    s->top=-1;
    reverse_string(s);
    return 0;
}

void push(STACK *s, char data)
{
    if(s->top == SIZE-1)
        printf("Stack Overflow\n");
    else
    {
        s->top ++;
        s->name[s->top] = data;
    }
}

char pop(STACK *s)
{
    char data;
    if(s->top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        data = s->name[s->top];
        s->top--;
        return data;
    }
}

void reverse_string(STACK *s)
{
    int i=0;
    char istring[SIZE],ostring[SIZE];
    scanf("%s",istring);
    while(istring[i] != '\0')
    {
        push(s, istring[i]);
        i++;
    }
    i=0;
    while(s->top != -1)
    {
        ostring[i] = pop(s);
        i++;
    }
    ostring[i] = '\0';
    if(strcmp(istring,ostring)==0)
        printf("%s is a palindrome string\n", ostring);
    else
        printf("%s is not a palindrome string\n", istring);
}

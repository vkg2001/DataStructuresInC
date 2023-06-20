#include <stdio.h>
#include <stdlib.h>

#define SIZE 25

struct stack
{
    int num[SIZE],top;
};
typedef struct stack STACK;

void push(STACK *s, int data);
int pop(STACK *s);
void reversenumber(STACK *s,int);

int main()
{
    int n;
    STACK st,*s;
    s=&st;
    s->top=-1;
    scanf("%d",&n);
    reversenumber(s,n);
    return 0;
}

void push(STACK *s,int data)
{
    if(s->top==SIZE-1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        s->top++;
        s->num[s->top]=data;
    }
}

int pop(STACK *s)
{
    int data;
    if(s->top==-1)
    {
        printf("Stack Underflow\n");
        return s->top;
    }
    else
    {
        data = s->num[s->top];
        s->top--;
        return data;
    }
}

void reversenumber(STACK *s,int n)
{
    int rem, factor=1, rev=0;
    int temp=n;
    while(n)
    {
        rem = n%10;
        push(s, rem);
        n = n/10;
    }
    while(s->top!=-1)
    {
        rev = rev + factor * pop(s);
        factor = factor *10;
    }
    if(rev == temp)
        printf("%d is a palindrome number\n", temp);
    else
        printf("%d is not a palindrome number\n", temp);
}

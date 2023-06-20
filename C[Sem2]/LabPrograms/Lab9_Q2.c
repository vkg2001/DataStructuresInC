#include<stdio.h>
#include<stdlib.h>
#define SIZE 20

struct stack
{
    int element[SIZE] ;
    int top ;
};
typedef struct stack STACK;

void push(STACK *s, int e);
int isEmpty(STACK *s);
int pop(STACK *s);
int peek(STACK * s);
void Luckywinner(STACK *s,int k);

int main ()
{
    STACK st ,*s;
    s=&st;
    s->top = -1;

    int N,k,i,U;
    printf("Enter the number of users\n");
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        printf("enter users Unique id\n");
        scanf("%d",&U);
        push(s,U);
    }
    printf("enter magic number\n");
    scanf("%d",&k);
    Luckywinner(s,k);
 }

 void Luckywinner(STACK *s,int k)
 {
    int x=0,y=0,m;
    while(!isEmpty(s))
    {
        m=pop(s);
        if(m%k==0)
        {
          printf("W ");
           x++;
        }
        else
        {
           printf("L ");
          y++;
      }
    }
    printf("\nNumber of lucky winners are: %d",x);
    printf("\nNumber of users who did not win the contest are: %d\n",y);
}

void push(STACK *s, int e)
{
    if(s->top == SIZE -1)
    {
        printf("Stack overflow\n");
    }
    else
    {
        s->element[++s->top]=e;
    }
}

int isEmpty(STACK *s)
{
    return s->top==-1;
}

int pop(STACK *s)
{
    if(isEmpty(s))
    {
        printf("Stack underflow\n");
    }
    else
    {
        int e = s->element[s->top--];
        return e;
    }
}

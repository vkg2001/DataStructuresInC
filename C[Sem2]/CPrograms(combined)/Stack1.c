#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

struct stack
{
    int num[SIZE],top;
};
typedef struct stack STACK;

void push(STACK *s,int data);
int pop(STACK *s);
void display(STACK *s);
int peek(STACK *s);

int main()
{
    int ch,data;
    STACK st,*s;
    s=&st;
    s->top=-1;
    printf("STACK OPERATIONS:\n");
    while(1)
    {
        printf("1.PUSH\t2.POP\t3.DISPLAY\t4.PEEK\t5.EXIT\nENTER YOUR CHOICE\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("ENTER DATA TO PUSH:\n");
                    scanf("%d",&data);
                    push(s,data);
                    break;
            case 2: data=pop(s);
                    if(s->top>=0)
                    printf("POPPED ELEMENT IS %d\n",data);
                    break;
            case 3: display(s);
                    break;
            case 4: data=peek(s);
                    if(s->top>=0)
                    printf("T ELEMENT IS %d\n",data);
                    break;
            case 5: exit(0);
            default: printf("INVALID CHOICE!\n");
        }
    }
    return 0;
}

void push(STACK *s,int data)
{
    if(s->top==SIZE-1)
        printf("STACK OVERFLOW\n");
    else{
        s->num[++s->top]=data;
    }
}

int pop(STACK *s)
{
    int data;
    if(s->top==-1)
        printf("STACK UNDERFLOW\n");
    else{
        data=s->num[s->top--];
        return data;
    }
}

void display(STACK *s)
{
    int i;
    if(s->top==-1)
        printf("STACK EMPTY\n");
    else{
        printf("top->\n");
        for(i=s->top;i>=0;i--)
            printf("%d\n",s->num[i]);
        printf("\n");
    }
}

int peek(STACK *s)
{
    int data;
    if(s->top==-1)
        printf("STACK EMPTY\n");
    else{
        data=s->num[s->top];
        return data;
    }
}

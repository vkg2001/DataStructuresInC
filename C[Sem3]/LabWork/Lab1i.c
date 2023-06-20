#include<stdio.h>
#include<stdlib.h>

#define SIZE 5

struct stack
{
    int num[SIZE],top1;
};
typedef struct stack STACK;

int top2;

void push(STACK *s,int data);
int pop(STACK *s);
void display(STACK *s);

int main()
{
    int ch,data;
    STACK st,*s;
    s=&st;
    s->top1=-1;
    printf("STACK OPERATIONS:\n");
    while(1)
        {
        printf("1.PUSH\t2.POP\t3.DISPLAY\t4.EXIT\nENTER YOUR CHOICE\n");
        scanf("%d",&ch);
        switch(ch)
        {
            int temp;
            STACK *b;
            case 1: printf("ENTER DATA TO PUSH:\n");
                    scanf("%d",&data);
                    if(s->top1==-1)
                    push(s,data);
                    else
                        while(s->top1>data||s->top1!=-1)
                    {
                        temp=pop(s);
                        push(b,temp);
                    }
                    push(s,data);
                    while(top2!=-1)
                    {
                        temp=pop(b);
                        push(s,temp);
                    }
                    break;
            case 2: data=pop(s);
                    if(s->top1>=0)
                    printf("POPPED ELEMENT IS %d\n",data);
                    break;
            case 3: printf("ELEMENTS ARE:\t");
                    display(s);
                    break;
            case 4: exit(0);
            default: printf("INVALID CHOICE!\n");
        }
    }
    return 0;
}

void push(STACK *s,int data)
{
    s->num[++s->top1]=data;
}

int pop(STACK *s)
{
    int data;
        data=s->num[s->top1--];
        return data;
}

void display(STACK *s)
{
    int i;
        printf("\ntop->\n");
        for(i=s->top1;i>=0;i--)
            printf("%d\n",s->num[i]);
        printf("\n");
 }

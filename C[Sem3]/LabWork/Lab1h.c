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

int main()
{
    int ch,data;
    STACK st,*s;
    s=&st;
    s->top=-1;
    printf("ENTER DATA TO PUSH:\n");
    scanf("%d",&data);
    printf("STACK OPERATIONS:\n");
    while(1)
        {
        printf("1.PUSH\t2.POP\t3.DISPLAY\t4.EXIT\nENTER YOUR CHOICE\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("ENTER DATA TO PUSH:\n");
                    scanf("%d",&data);
                    break;
            case 2: data=pop(s);
                    if(s->top>=0)
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
    s->num[++s->top]=data;
}

int pop(STACK *s)
{
    int data;
        data=s->num[s->top--];
        return data;
}

void display(STACK *s)
{
    int i;
        printf("\ntop->\n");
        for(i=s->top;i>=0;i--)
            printf("%d\n",s->num[i]);
        printf("\n");
 }

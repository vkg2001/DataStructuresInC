#include<stdio.h>
#include<stdlib.h>

#define MAX 6

typedef struct q
{
    int items[MAX];
    int front,rear;
}QUEUE;

QUEUE create_queue()
{
    QUEUE q1;
    q1.front=-1;
    q1.rear=-1;
    return q1;
}

void enqueue(QUEUE *q1,int ele)
{
    if(q1->front==-1&&q1->rear==-1)
    {
        q1->front=0;
        q1->rear=0;
        q1->items[q1->rear]=ele;
    }
    else if((q1->rear+1)%MAX==q1->front)
        printf("queue overflow\n");
    else
    {
        q1->rear=(q1->rear+1)%MAX;
        q1->items[q1->rear]=ele;
    }
}

void dequeue(QUEUE *q1)
{
    if(q1->front==-1&&q1->rear==-1)
        printf("queue underflow");
    else if(q1->front==q1->rear)
    {
        printf("dequeued element is %d",q1->items[q1->front]);
        q1->front=-1;
        q1->rear=-1;
    }
    else{
        printf("dequeued element is %d",q1->items[q1->front]);
        q1->front=(q1->front+1)%MAX;
    }
}

void display(QUEUE *q1)
{
    int i=0;
    if(q1->front==-1&&q1->rear==-1)
        printf("queue underflow\n");
    else if(q1->rear>=q1->front)
    {
        printf("circular queue elements are \n");
        for(i=q1->front;i<=q1->rear;i++)
            printf("%d\t",q1->items[i]);
    }
    else
    {
        printf("circular queue elements are \n");
        for(i=q1->front;i<MAX;i++)
            printf("%d",q1->items[i]);
        for(i=0;i<=q1->rear;i++)
            printf("%d",q1->items[i]);
    }
}

int main()
{
    int ch,ele;
    QUEUE q11,*q1;
    q11=create_queue();
    q1=&q11;
    while(1)
    {
        printf("\nCircular Queue MENU.\n1. ENQUEUE\n2. DEQUEUE\n3. DISPLAY\n4.EXIT\n");
        printf("enter choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("enter element to enqueue:");
            scanf("%d",&ele);
            enqueue(q1,ele);
            break;
            case 2:dequeue(q1);
            break;
            case 3:display(q1);
            break;
            case 4:exit(0);
            default:printf("invalid chioce!\n");
        }
    }
    return 0;
}

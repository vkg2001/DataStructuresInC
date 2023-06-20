
#include<stdio.h>
#include<stdlib.h>

# define SIZE 6

struct q
{

    int items[SIZE];
    int front,rear;
};

typedef struct q QUEUE;

QUEUE create_queue()
{
    QUEUE q1;
    q1.front=-1;
    q1.rear=-1;
    return q1;
}

void enqueue (QUEUE *q1,int element)
{

    if(q1->front==-1 && q1->rear==-1)
    {
        q1->front=0;
        q1->rear=0;
        q1->items[q1->rear]=element;
    }
    else if ((q1->rear+1)%SIZE==q1->front)
    {
        printf("queue overflow\n");
    }
    else
    {
        q1->rear=(q1->rear+1)%SIZE;
        q1->items[q1->rear]=element;
    }
}

void dequeue (QUEUE *q1)
{

    if(q1->front==-1 && q1->rear==-1)
    {
        printf("queue undeflow");
    }
    else if (q1->front==q1->rear)
    {
        printf("dequeued elememt is %d",q1->items[q1->front]);
        q1->front=-1;
        q1->rear=-1;
    }
    else
    {
        printf("dequeued elememt is %d",q1->items[q1->front]);
        q1->front=(q1->front+1)%SIZE;
    }
}

void display(QUEUE *q1)
{
    int i;
    if(q1->front==-1 && q1->rear==-1)
    {
        printf("queue undeflow");
    }
    else if (q1->front<=q1->rear)
    {
        printf("circular queue elements are\n");
        for (i=q1->front;i<=q1->rear;i++)
        {
            printf("%d",q1->items[i]);
        }
    }
    else
    {
        printf("circular queue elements are\n");
        for(i=q1->front;i<SIZE;i++)
        {
            printf("%d",q1->items[i]);
        }
        for(i=0;i<=q1->rear;i++)
        {
         printf("%d",q1->items[i]);
        }
    }
}
int main()
{
    int ch, element;
    QUEUE q11, *q1;
    q11 = create_queue();
    q1 = &q11;
    while(1)
    {
        printf("\nCircular Queue Menu.\n1. ENQUEUE. 2. DEQUEUE. 3. DISPLAY. 4. EXIT. \n");
        printf("Enterr the choice: \n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter the element to enqueue: ");
                            scanf("%d", &element);
                            enqueue(q1, element);
                            break;
            case 2: dequeue(q1);
                            break;
            case 3: display(q1);
                            break;
            case 4: exit(0);
            default: printf("invalid choice.\n");
        }
    }
    return 0;
}


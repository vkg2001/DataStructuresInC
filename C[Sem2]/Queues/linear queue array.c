#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

struct q
{
    int items[SIZE];
    int front;
    int rear;
};
typedef struct q QUEUE;

QUEUE create_queue()
{
    QUEUE q1;
    q1.front = 0;
    q1.rear = -1;
    return q1;
}

void enqueue(QUEUE *q1, int element)
{
    if(q1->rear == SIZE-1)
        printf("Queue Overflow\n");
    else
    {
         q1->rear ++;
         q1->items[q1->rear] = element;

    }
}

int dequeue(QUEUE *q1)
{
    if(q1->front == q1->rear+1)
        printf("Queue Underflow\n");
    else
    {
        return q1->items[q1->front++];
    }
}

void displayqueue(QUEUE *q1)
{
    int i;
    if(q1->front == q1->rear+1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        for(i=q1->front; i<q1->rear+1; i++)
            printf("%d ", q1->items[i]);
        printf("\n");
    }
}

int main()
{
    int i, n,element;
    QUEUE q11, *q1;
    q11 = create_queue();
    q1=&q11;
    printf("Enter number of elements to enqueue\n");
    scanf("%d",&n);
    if(n>SIZE)
    {
        printf("Number of elements to enqueue are more than the size of queue\n");
    }
    else
    {
        for(i=0;i<n;i++)
        {
            printf("Enter element to enqueue: ");
            scanf("%d", &element);
            enqueue(q1, element);
        }
        displayqueue(q1);

        element = dequeue(q1);
        printf("Dequeued element is %d\n", element);
        printf("After dequeue \n");
        displayqueue(q1);

        element = dequeue(q1);
        printf("Dequeued element is %d\n", element);
        printf("After dequeue \n");
        displayqueue(q1);

        element = dequeue(q1);
        printf("Dequeued element is %d\n", element);
        printf("After dequeue \n");
        displayqueue(q1);

        element = dequeue(q1);
        printf("Dequeued element is %d\n", element);
        printf("After dequeue \n");
        displayqueue(q1);

        element = dequeue(q1);
        printf("Dequeued element is %d\n", element);
        printf("After dequeue 1\n");
        displayqueue(q1);
    }
    return 0;
}

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
    q1.front=0;
    q1.rear=-1;
    return q1;
}

void enqueue(QUEUE *q1,int ele)
{
    if(q1->rear==SIZE-1)
        printf("queue overflow\n");
    else
    {
        q1->rear++;
        q1->items[q1->rear]=ele;
    }
}

int dequeue(QUEUE *q1)
{
    if(q1->front==q1->rear+1)
        printf("queue underflow\n");
    else
        return q1->items[q1->front++];
}

void display(QUEUE *q1)
{
    int i=0;
    if(q1->front==q1->rear+1)
        printf("queue underflow\n");
    else
    {
        for(i=q1->front;i<=q1->rear;i++)
        {
            printf("%d\t",q1->items[i]);
        }
        printf("\n");
    }
}

int main()
{
    int i,n,ele;
    QUEUE q11,*q1;
    q11=create_queue();
    q1=&q11;
    printf("enter number of elements in queue\n");
    scanf("%d",&n);
    if(n>SIZE)
        printf("no. of elements more than given size\n");
    else
    {
        for(i=0;i<n;i++)
        {
            printf("enter element to be enqueued\n");
            scanf("%d",&ele);
            enqueue(q1,ele);
        }
        display(q1);

        ele=dequeue(q1);
        printf("Dequeue element is %d\n",ele);
        printf("After removing first element\n");
        display(q1);

        ele=dequeue(q1);
        printf("Dequeue element is %d\n",ele);
        printf("After removing second element\n");
        display(q1);

        ele=dequeue(q1);
        printf("Dequeue element is %d\n",ele);
        printf("After removing third element\n");
        display(q1);

        ele=dequeue(q1);
        printf("Dequeue element is %d\n",ele);
        printf("After removing fourth element\n");
        display(q1);

        ele=dequeue(q1);
        printf("Dequeue element is %d\n",ele);
        printf("After removing fifth element\n");
        display(q1);
    }
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
#define MAXQUEUE 5

struct indices
{
    int front1;
    int rear1;
    int front2;
    int rear2;
    int produce;
    int consume;
};

struct prod_cons
{
    int data[MAXQUEUE];
    struct indices index;
};
typedef struct prod_cons PC;

int full(PC* q);
int empty(PC* q);
void Produce_in_Produce(PC* q);
void Produce_in_Consume(PC* q);
void Consume_from_Produce(PC* q);
void Consume_from_Consume(PC* q);
void Print_Producer_Consumer(PC q,PC p);
void Get_the_Active_Producer_and_Consumer(PC q,PC p);

int main()
{
    PC p,q;
    q.index.front1=0;
    q.index.rear1=-1;
    q.index.consume=0;
    q.index.produce=0;
    p.index.front2=0;
    p.index.rear2=-1;
    p.index.consume=0;
    p.index.produce=0;
    int choice;
    while(1)
    {
        printf("\n1. Produce in Producer\n2. Consume from Consumer\n3. Produce in Consumer\n4. Consume from Producer\n5. Print Producer Consumer\n6. Get the Active Producer and Consumer\n7. Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1: Produce_in_Produce(&q);
                break;
        case 2: Consume_from_Consume(&p);
                break;
        case 3: Produce_in_Consume(&p);
                break;
        case 4: Consume_from_Produce(&q);
                break;
        case 5: Print_Producer_Consumer(q,p);
                break;
        case 6: Get_the_Active_Producer_and_Consumer(q,p);
                break;
        case 7: printf("End process\n");
                exit(0);

        }
    }
}

int full(PC* q)
{
    if(q->index.rear1==MAXQUEUE-1)
    {
        return 1;
    }else
    {
        return 0;
    }
}

void Produce_in_Produce(PC* q)
{
    if(full(q))
    {
        printf("Stack is full\n");
        return;
    }
    q->index.produce=1;
    int lower=1, upper=100;
    printf("Data entered into queue 'produce'\n");
    int num=(rand()%(upper-lower+1))+lower;
    q->data[++q->index.rear1] = num;
}

void Produce_in_Consume(PC* q)
{
    if(full(q))
    {
        printf("Stack is full\n");
        return;
    }
    q->index.produce=1;
    int lower=100, upper=200;
    printf("Data entered into queue 'consume'\n");
    int num=(rand()%(upper-lower+1))+lower;
    q->data[++q->index.rear2] = num;
}

int empty(PC* q)
{
    if(q->index.front1>q->index.rear1)
    {
        return 1;
    }else
    {
        return 0;
    }
}

void Consume_from_Produce(PC* q)
{
    if(empty(q))
    {
        printf("Queue is empty\n");
        return;
    }
    q->index.consume=1;
    int x=q->data[q->index.front1];
    q->index.front1++;
    printf("Deleted: %d\n",x);
}

void Consume_from_Consume(PC* q)
{
    if(empty(q))
    {
        printf("Queue is empty\n");
        return;
    }
    q->index.consume=1;
    int x=q->data[q->index.front2];
    q->index.front2++;
    printf("Deleted: %d\n",x);
}

void Print_Producer_Consumer(PC q,PC p)
{
    int qflag=0;
    int pflag=0;
    if(empty(&q))
    {
        printf("Queue is empty\n");
        qflag=1;
    }
    if(qflag==0){
        printf("Producer\n");
        for(int i=q.index.front1;i<=q.index.rear1;i++)
        {
                printf("%d ",q.data[i]);
        }
    }

    if(empty(&p))
    {
        printf("Queue is empty\n");
        pflag=1;
    }
    if(pflag==0)
    {
        printf("\nConsumer\n");
        for(int i=p.index.front2;i<=p.index.rear2;i++)
        {
                printf("%d ",p.data[i]);
        }
    }
    printf("\n");
}

void Get_the_Active_Producer_and_Consumer(PC q,PC p)
{
    if(q.index.consume==1&&q.index.produce==1)
    {
        printf("Active:Producer\n");
        for(int i=q.index.front1;i<=q.index.rear1;i++)
        {
                printf("%d ",q.data[i]);
        }
    }

    if(p.index.consume==1&&p.index.produce==1)
    {
        printf("\nActive:Consumer\n");
        for(int i=p.index.front2;i<=p.index.rear2;i++)
        {
                printf("%d ",p.data[i]);
        }
    }
    printf("\n");
}

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define size 6
struct recharge
{
    char m_no[size][20];
    int cost[size];
     char r_type[size][20];
    int front,rear;
};
typedef struct recharge queue;
queue create_queue()
{
    queue q1;
    q1.front=-1;
    q1.rear=0;
        return q1;
}
void enqueue(queue *q1)
{

    char m_no[20], r_type[20];
    int cost;
    if(q1->rear == size)

    {
        printf("Queue Overflow\n");
    }
    else
    {

        scanf("%s %d %s", m_no,&cost, r_type);
        strcpy(q1->m_no[q1->rear],m_no);
        strcpy(q1->r_type[q1->rear], r_type);
        q1->rear++;
    }
    void sum(queue *q1)
    {
        int i,precount=0,postcount=0;
        if(q1->rear==q1->front+1)
        {
            printf("Queue Empty");
        }
        else
        {
             for(i=q1->front+1; i<q1->rear; i++)
             {
                 if(strcmp(q1->r_type,"postpaid")==0)
                   printf("%s %d %s\n", q1->m_no[i], q1->cost[i], q1->r_type[i]);
                    postcount+=q1->cost[i];
             }
            printf("%d",postcount);

        }
    }
}

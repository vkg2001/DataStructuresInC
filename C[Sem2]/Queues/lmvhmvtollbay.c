/*1. A new Toll bay is setup at Airport Road. There are different types of vehicles passing through the toll.
Vehicles are categorized as LMV and HMV. The charges for LMV passing by toll is Rs. 50 and HMV passing by toll is Rs. 100 each time vehicles pass.
Apply Problem Solving Framework to perform the following:
1. Read and display the vehicles details.
2. Display only HMV vehicle details.
3. Count the LMV vehicles.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 10

struct q
{
    char vnum[SIZE][12];
    char vtype[SIZE][SIZE];
    int cost[SIZE];
    int front;
    int rear;
};
typedef struct q QUEUE;

QUEUE create_queue()
{
    QUEUE q1;
    q1.front = -1;
    q1.rear = 0;
    return q1;
}

void enqueue(QUEUE *q1)
{
    char vcnum[10], vctype[5];
    if(q1->rear == SIZE)
        printf("Queue Overflow\n");
    else
    {
        printf("Enter vehicle number, vehicle type (as LMV or HMV)\n");
        scanf("%s%s", vcnum, vctype);
        strcpy(q1->vnum[q1->rear],vcnum);
        strcpy(q1->vtype[q1->rear], vctype);
        if(strcmp(q1->vtype[q1->rear],"HMV")==0)
            q1->cost[q1->rear]= 100;
        else
            q1->cost[q1->rear]= 50;
        q1->rear ++;
    }
}

void dequeue(QUEUE *q1)
{
    if(q1->rear == q1->front +1)
        printf("Queue Underflow\n");
    else
    {
        q1->front++;
        printf("Vehicle moving out of toll: %s. %s. \n", q1->vnum[q1->front], q1->vtype);
    }
}


void displayqueue(QUEUE *q1)
{
    int i;
    if(q1->rear == q1->front+1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Vehicles at Toll bay are: \n");
        for(i=q1->front+1; i<q1->rear; i++)
        {
                printf("%s %s %d\n", q1->vnum[i], q1->vtype[i], q1->cost[i]);
        }
        printf("\n");
    }
}

void predicthmvcost(QUEUE *q1)
{
    int i, totalhmvcost=0;
    if(q1->rear == q1->front+1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        for(i=q1->front+1; i<q1->rear; i++)
        {
            if(strcmp(q1->vtype[i], "HMV")==0)
                totalhmvcost = totalhmvcost + q1->cost[i];
        }
        printf("Predicted Total cost of HMV is %d\n", totalhmvcost);
    }
}

void predictlmvcost(QUEUE *q1)
{
    int i, totallmvcost=0;
    if(q1->rear == q1->front+1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        for(i=q1->front+1; i<q1->rear; i++)
        {
            if(strcmp(q1->vtype[i], "LMV")==0)
                totallmvcost = totallmvcost + q1->cost[i];
        }
        printf("Predicted Total cost of LMV is %d\n", totallmvcost);
    }
}

void displayqueuevehicles(QUEUE *q1)
{
    int i, lmvcount=0;
    if(q1->rear == q1->front+1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Vehicles at Toll bay are: \n");
        for(i=q1->front+1; i<q1->rear; i++)
        {
            if(strcmp(q1->vtype[i], "HMV")==0)
                printf("%s %s %d\n", q1->vnum[i], q1->vtype[i], q1->cost[i]);
            else
                lmvcount++;
        }
        printf("\n");
    }
    printf("Number of LMV vehicles waiting to pass toll are: %d\n", lmvcount);
}


int main()
{
    int i, n;
    QUEUE q11, *q1;
    q11 = create_queue();
    q1=&q11;
    printf("Enter number of vehicles waiting at Toll bay?\n");
    scanf("%d",&n);
    if(n>SIZE)
    {
        printf("Number of vehicles to enqueue are more than the size of toll bay.\n");
    }
    else
    {
        for(i=0;i<n;i++)
        {
            enqueue(q1);
        }
        displayqueue(q1);
        printf("HMV vehicles are: \n");
        displayqueuevehicles(q1);
        predicthmvcost(q1);
        predictlmvcost(q1);
    }
    return 0;
}

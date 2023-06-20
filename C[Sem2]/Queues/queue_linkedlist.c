#include<stdio.h>
#include<stdlib.h>

typedef struct queue
{
    int data;
    struct queue *next;
}*NODE;

NODE rear=NULL;

NODE create_queue()
{
    NODE newn;
    newn=malloc(sizeof(struct queue));
    if(newn==NULL)
        return NULL;
    else
    {
        printf("Enter data\n");
        scanf("%d",&newn->data);
        newn->next=NULL;
        return newn;
    }
}

NODE enqueue(NODE head)
{
   NODE temp;
   temp=create_queue();
   if(temp==NULL)
   {
       printf("Cannot insert\n");
       return head;
   }
   if(head==NULL)
   {
       rear=temp;
       return temp;
   }
   else
   {
       rear->next=temp;
       rear=rear->next;
       return head;
   }
}

NODE dequeue(NODE head)
{
    if(head==NULL)
        printf("Underflow\n");
    else
    {
        NODE cur=head;
        printf("Dequeued element is : %d\n",head->data);
        head=head->next;
        free(cur);
    }
    return head;
}

void display(NODE head)
{
    if(head==NULL)
    {
        printf("Underflow\n");
    }
    else
    {
      NODE cur=head;
      printf("elements in queue are : ");
      while(cur!=NULL)
      {
          printf("%d\t",cur->data);
          cur=cur->next;
      }
      printf("\n");
    }
}

int main()
{
    int m,n,i,j;
    NODE head=NULL;
    printf("Enter number of elements\n");
    scanf("%d",&m);
    for(i=0;i<m;i++)
        head=enqueue(head);
     display(head);
     printf("Enter no. of times to remove\n");
     scanf("%d",&n);
     for(j=0;j<n;j++)
     {
         head=dequeue(head);
         display(head);
     }
     return 0;
}

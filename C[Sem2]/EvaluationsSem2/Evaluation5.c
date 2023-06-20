#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct recharge
{
    int amt;
    char type[20];
    long long int number;
    struct recharge *next;
};

typedef struct recharge *QUEUE;

QUEUE create_queue()
{
    QUEUE newn=(QUEUE)malloc(sizeof(struct recharge));
    if (newn == NULL)
    {
        printf("Not created\n");
        exit(0);
    }
    newn->next = NULL;
    scanf("%lld %d %s",&newn->number,&newn->amt,newn->type);
    return newn;
}

QUEUE enqueue(QUEUE head)
{
    QUEUE newn=create_queue(),cur=head;
    if(head==NULL)
    {
       return newn;
    }
   else
    {
        cur=head;
        while(cur->next!=NULL)
        {
        cur=cur->next;
        }
        cur->next=newn;
    }
    return head;
}

void rechargeapplication(QUEUE head)
{
    int post=0,pre=0,flag1=0,flag2=0;
    QUEUE cur=head;
        printf("Postpaid Requests\n");
        while(cur!=NULL)
        {
            if(strcmp("postpaid",cur->type)==0)
            {
                post+=cur->amt;
                flag1=1;
            }
            cur=cur->next;
        }
            if(flag1==1)
            {
                cur=head;
                 while(cur!=NULL)
                 {
                     if(strcmp("postpaid",cur->type)==0)
                     {
                        printf("%lld %d %s\n",cur->number,cur->amt,cur->type);
                     }
                     cur=cur->next;
                  }
                printf("%d\n",post);
            }
            else
            {
                printf("Queue Empty\n0\n");
            }
         cur=head;
        printf("Prepaid Requests\n");
        while(cur!=NULL)
        {
            if(strcmp("prepaid",cur->type)==0)
            {
                pre+=cur->amt;
                flag2=1;
            }
            cur=cur->next;
        }
        if(flag2==1)
        {
           cur=head;
           while(cur!=NULL)
           {
               if(strcmp(cur->type,"prepaid")==0)
               {
                   printf("%lld %d %s\n",cur->number,cur->amt,cur->type);
               }
               cur=cur->next;
          }
           printf("%d\n",pre);
        }
       else
      {
          printf("Queue Empty\n0\n");
      }
}

int main()
{
    QUEUE head=NULL;
    int i,n;
    scanf("%d",&n);
    if(n>0&&n<100)
    {
        for(i=0;i<n;i++)
        {
            head=enqueue(head);
        }
        rechargeapplication(head);
    }
    return 0;
}

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct pay
{   char type[20];
    int id;
    int amnt;
    struct pay *next;
};

typedef  struct pay *node;

node getnode()
{
    node newn=(node)malloc(sizeof(struct pay));
    if(newn==NULL)
    {   printf("memory not allocated\n");
        exit(0);
    }
    else
    {
        scanf("%s %d %d",newn->type,&newn->amnt,&newn->id);
        newn->next=NULL;
    }
    return newn;
}


node insert(node head)
{
    node newn=getnode();
    node cur=head;
    if(head==NULL)
    {
        head=newn;
        return newn;
    }
    else
    {
        newn->next=cur;
        head=newn;
    }
    return head;
}

void display(node head)
{
    node cur=head;
   if(head==NULL)
  {
     printf("list is empty\n");
  }
else
    {
        printf("the nodes are ; ");
      while(cur!=NULL)
       {
         printf("%s %d %d\n",cur->type,cur->amnt,cur->id);
           cur=cur->next;
       }
    }
}
void search(node head)
{
    node cur=head;
    char sty[20];
    int flag=0;
    printf("enter the type of transc u want to search\n");
    scanf("%s",sty);
    if(head==NULL)
    {
        printf("list is empty\n");
    }
    else
    {
        while(cur!=NULL)
        {
            if(strcmp(cur->type,sty)==0)
            {    flag=1;
                 printf("%s %d %d\n",cur->type,cur->amnt,cur->id);
            }
            cur=cur->next;
      }
      if(flag==0)
      {
          printf("there is no such transction\n");
      }
    }
}

void search_id(node head)
{
    node cur=head;
    int fid;
    printf("enter the id you want to search\n");
    scanf("%d",&fid);
   int flag=0;
    if(head==NULL)
    {
        printf("no list is present\n");
    }
    else
    {
        while(cur!=NULL)
        {
            if(cur->id==fid)
            {
                flag=1;
               printf("%s %d %d\n",cur->type,cur->amnt,cur->id);
            }
            cur=cur->next;
      }
      if(flag==0)
      {
          printf("there is no such transction\n");
      }

}
}
node duplicate(node head)
{
    node temp=NULL,index=NULL,cur=head;
    if(head==NULL)
    {
        printf("list is empty\n");
    }
    else
    {
        while(cur!=NULL)
        {
            temp=cur;
            index=cur->next;
            while(index!=NULL)
            {
                if(cur->id==index->id)
                {
                    temp->next=index->next;
                    free(temp);
                    break;
                }
                else
                {
                    temp=index;
                }
                index=index->next;
            }
            cur=cur->next;
        }
    }
    return head ;
}

int main()
{   node head=NULL;
    int i,n;
    printf("enter the nos of transaction\n");
    scanf("%d",&n);
    printf("enter the details; type amount and id\n");
    for(i=0;i<n;i++)
    {
        head=insert(head);
    }
    display(head);
    search(head);
    search_id(head);
    head=duplicate(head);
    display(head);
    return 0;
}

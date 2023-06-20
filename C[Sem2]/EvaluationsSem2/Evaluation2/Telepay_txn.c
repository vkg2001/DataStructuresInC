//search
//search_id
//delete_duplicate

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct telepay
{
    char type[20];
    int tid;
    float amt;
    struct telepay *next;
};
typedef struct telepay *NODE;

NODE getnode();
NODE insert_end(NODE head);
void display(NODE head);
void search(NODE head);
void search_id(NODE head);
NODE del_dup(NODE head);

int main()
{
    NODE head=NULL;
    int n;
    printf("ENTER NUMBER OF TRANSACTIONS:\t");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        {
            head=insert_end(head);
        }
    display(head);
    search(head);
    search_id(head);
    head=del_dup(head);
    printf("\nModified List");
    display(head);
    return 0;
}

NODE getnode()
{
    NODE newn=(NODE)malloc(sizeof(struct telepay));
    if(newn==NULL)
    {
        printf("MEMORY NOT ALLOCATED\n");
        exit(0);
    }
    printf("ENTER TRANSACTION TYPE, AMOUNT & ID\n");
    scanf("%s %f %d",newn->type,&newn->amt,&newn->tid);
    newn->next=NULL;
    return newn;
}

NODE insert_end(NODE head)
    {
    NODE cur=head;
    NODE newn=getnode();
    if(head==NULL)
    {
        head=newn;
    }
    else
    {
        while(cur->next!=NULL)
        {
            cur=cur->next;
        }
        cur->next=newn;
    }
    return head;
}

void display(NODE head)
{
    NODE cur=head;
    if(head==NULL)
    {
        printf("LIST IS EMPTY\n");
    }
    else
    {
        while(cur!=NULL)
        {
            printf("%s %f %d\n",cur->type,cur->amt,cur->tid);
            cur=cur->next;
        }
    }
}

void search(NODE head)
{
    char stype[20];
    int flag=0;
    printf("ENTER TYPE OF TRANSACTION TO BE SEARCHED\n");
    scanf("%s",stype);
    NODE cur=head;
    if(head==NULL)
    {
        printf("LIST IS EMPTY\n");
    }
    else
    {
        while(cur!=NULL)
        {
        if(strcmp(cur->type,stype)==0)
        {
            flag=1;
            printf("%s %f %d\n",cur->type,cur->amt,cur->tid);
        }
        cur=cur->next;
        }
        if(flag==0)
        {
            printf("TRANSACTION NOT FOUND\n");
        }
    }
}

void search_id(NODE head)
{
    int sid,flag=0;
    printf("ENTER TXN ID TO BE SEARCHED\n");
    scanf("%d",&sid);
    NODE cur=head;
    if(head==NULL)
    {
        printf("LIST IS EMPTY\n");
    }
    else
    {
        while(cur!=NULL)
        {
            if(cur->tid==sid)
            {
                flag=1;
                printf("%s %f %d\n",cur->type,cur->amt,cur->tid);
            }
            cur=cur->next;
            }
            if(flag==0)
            {
                printf("TRANSACTION ID NOT FOUND\n");
            }
        }
}

NODE del_dup(NODE head)
{
    char stype[20];
    int count=0,flag=0;
    printf("\nEnter type of transaction to be searched for duplicates\n");
    scanf("%s",stype);
    NODE cur,prev;
    cur=prev=head;
    if(head==NULL)
    {
        printf("list is empty\n");
    }
    else
    {
        while(cur!=NULL)
        {
            if(strcmp(cur->type,stype)==0)
            {
                flag=1;
                count++;
            }
            cur=cur->next;
        }
        if(flag==0)
        {
            printf("transaction not found\n");
            exit(0);
        }
        else
        {
            if(count>1)
            {
                cur=head;
                if(strcmp(cur->type,stype)==0)
                {
                    head = head->next;
                    cur->next=NULL;
                    free(cur);
                    return head;
                }
                cur=cur->next;
                while(cur!=NULL)
                {
                    if(strcmp(cur->type,stype)==0)
                    {
                        break;
                    }
                    prev= cur;
                    cur= cur->next;
                }
                if(cur!=NULL)
                {
                    prev->next = cur->next;
                    cur->next=NULL;
                    free(cur);
                    printf("First occurrence of type is deleted\n");
                    return head;
                }
            }
            else
            {
                printf("The transaction type is unique\n");
                exit(0);
            }
        }
    }
}

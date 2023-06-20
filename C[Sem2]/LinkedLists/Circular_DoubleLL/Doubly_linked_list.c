#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

typedef struct node *NODE;

NODE getnode()
{
    NODE nn=(NODE)malloc(sizeof(struct node));
    if(nn==NULL)
    {
        printf("NOt created");
        exit(0);
    }
    printf("Enter details:\n");
    scanf("%d",&nn->data);
    nn->prev=NULL;
    nn->next=NULL;
    return nn;
}

NODE insert_front(NODE head)
{
    NODE nn=getnode();
    if(head==NULL)
    {
        head=nn;
        nn->next=NULL;
        return nn;
    }
    nn->next=head;
    head->prev=nn;
    head=nn;
    return head;
}

NODE insert_end(NODE head)
{
    NODE nn=getnode();
    if(head==NULL)
    {
        nn->prev=NULL;
        head=nn;
        return nn;
    }
    else
    {
        NODE cur=head;
        while(cur->next!=NULL)
            cur=cur->next;
            cur->next=nn;
            nn->prev=cur;
            return head;
    }
}

NODE insert_specific(NODE head,int loc)
{
    NODE nn=getnode();
    NODE cur=head,temp;
    if(head==NULL)
    {
        nn->prev=nn->next=NULL;
        head=nn;
    }
    else
    {
        while(cur->data!=loc)
        {
            if(cur->next==NULL)
            {
                printf("Node not found");
                exit(0);
            }
            else
            {
                cur=cur->next;
            }
        }
        temp=cur->next;
        cur->next=nn;
        nn->prev=cur;
        nn->next=temp;
        temp->prev=nn;
        printf("Insertion Success\n");
    }
    return head;
}

void display_list(NODE head)
{
    if(head==NULL)
    {
        printf("List is Empty\n");
    }
    else
    {
        NODE cur=head;
        printf("head-> ");
        do
        {
            printf("%d -> ", cur->data);
            cur = cur->next;
        }while(cur!=NULL);
        printf("NULL\n");
    }
}

int main()
{
    NODE head=NULL;
    int ch,cnt,loc;
    while(1)
    {
        printf("Menu -- 1. Insert End 2. Insert Front 3. Insert specific 4. Display 5. Exit\nEnter choice:\t");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: head = insert_end(head);
                            break;
            case 2: head = insert_front(head);
                            break;
            case 3: printf("Enter the location you want to insert:\t");
                    scanf("%d",&loc);
                    head=insert_specific(head,loc);
                            break;
            case 4: display_list(head);
                            break;
            case 5: exit(0);
                    break;
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node* NODE;

NODE insert_end(NODE);
void Display(NODE);
NODE getNode();
NODE Delete_front(NODE);

void main()
{
    int choice;
    NODE head=NULL;

    while(1)
    {
      printf("\nPress\n 1 for Enqueue \n 2 for display\n 3 for dequeue \n 4 for exit\n");
      scanf("%d",&choice);

        switch(choice)
        {
            case 1:head=insert_end(head);
                    break;

            case 2:Display(head);
                    break;

            case 3: head= Delete_front(head);
                    break;

            case 4:exit(0);
                    break;
            default:printf("Invalid choice\n");
        }
    }
}

NODE getNode()
{
    NODE NEWNODE;
    int ele;
    NEWNODE=malloc(sizeof(struct node));
    if(NEWNODE==NULL)
    {
        printf("Memory is not allocated\n");
    }
    printf("Enter the data part\n");
    scanf("%d",&ele);

    NEWNODE->data=ele;
    NEWNODE->next=NULL;

    return NEWNODE;
}


NODE Delete_front(NODE head)
{
    if(head==NULL)
    {
        printf("Queue is Underflow!!\n");
        return head;
    }
    NODE cur=head;
    head=head->next;
    printf("\nDequeued node data %d\n",cur->data);
    free(cur);
    return head;
}

NODE insert_end(NODE head)
{
    NODE Newnode=getNode();
    if(head==NULL)
    {
        head=Newnode;
        return head;
    }
    else
    {
        NODE temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=Newnode;

        return head;
    }
}

void Display(NODE head)
{
    if(head==NULL)
    {
        printf("Queue is Empty\n");
        return;
    }
    NODE temp=head;
    while(temp!=NULL)
    {
        printf("%d-->",temp->data);
        temp=temp->next;
    }
}


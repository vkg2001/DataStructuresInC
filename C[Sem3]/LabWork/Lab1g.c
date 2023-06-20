#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int data;
    struct stack *next;
};
typedef struct stack *NODE;

NODE head,temp,nnode,new_node;

NODE push(NODE);
NODE pop(NODE);
void display(NODE);

int main()
{
    head=NULL;
    int n,k;
    printf("enter number of elements in stack");
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        {
            head=push(head);
        }
    display(head);
    printf("enter number of elements to be removed from stack");
    scanf("%d",&k);
    for (int i=1;i<=k;i++)
        {
            head=pop(head);
        }
}

NODE get_node()
{
    nnode=(NODE)malloc(sizeof(struct stack));
    if(nnode==NULL)
    {
        printf("memory not allocated\n");
        exit(0);
    }
    else
    {
        scanf("%d",&nnode->data);
        nnode->next=NULL;
    }
    return nnode;
}

NODE push(NODE head)
{
    new_node=get_node();
    if(head==NULL)
    {
        head=new_node;
        head->next=NULL;
    }
    else
    {
        new_node->next=head;
        head=new_node;
    }
    return (head);
}

NODE pop(NODE head)
{
        printf("\nremoved element is %d \n",head->data);
        temp=head;
        head=head->next;
        free(temp);
    return(head);
}

void display(NODE head)
{
    if(head==NULL)
    {
        printf("nothing to display\n");
    }
    else
    {
        temp=head;
        printf("elements are\n");
        while(temp!=NULL)
        {
            printf("%d \t ",temp->data);
            temp=temp->next;
        }
    }
}

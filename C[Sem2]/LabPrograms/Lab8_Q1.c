#include<stdio.h>
#include<stdlib.h>

struct riping
{
    int mango;
    struct riping *next;
    struct riping *prev;
};

typedef struct riping *NODE;

NODE getnewnode();
NODE insert_end(NODE head);
NODE delete_front(NODE head);
void mangoes_fell(NODE head);
void display(NODE head);

int main()
{
    NODE head=NULL;
    int n;
    printf("Enter number of mangoes:\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        head=insert_end(head);
    }
    mangoes_fell(head);
    return 0;
}

NODE getnewnode()
{
    NODE newn=(NODE)malloc(sizeof(struct riping));
    if(newn==NULL)
    {

        printf("Memory not allocated\n");
        exit(0);
    }
    else
    {
        scanf("%d",&newn->mango);

        newn->next=newn;
        newn->prev=newn;
    }
}

NODE insert_end(NODE head)
{
    NODE cur=NULL;
    NODE newn=getnewnode();
    if(head==NULL)
        head=newn;
    else
    {
        cur=head->prev;

        cur->next=newn;
        newn->prev=cur;

        newn->next=head;
        head->prev=newn;
    }
    return head;
}

NODE delete_front(NODE head)
{
    NODE temp=NULL,cur=NULL;
    if(head==NULL)
    {
        printf("CDLL mangoes list is empty\n");
    }
    else if(head->next==head)
    {
        printf("Mango fell: %d\n",head->mango);
        free(head);
        head=NULL;
    }
    else
    {
        cur=head->prev;
        temp=head;
        head=head->next;
        head->prev=cur;
        cur->next=head;
        printf("Mango fell: %d\n",temp->mango);
        free(temp);
    }
    return head;
}

void mangoes_fell(NODE head)
{
    int cnt=0,cnt1=0;
    NODE t=NULL;
    if(head==NULL)
        printf("Mangoes list is empty\n");
    else
    {
        t=head->prev;
        while(head!=t)
        {
            if(head->mango>head->next->mango)
            {
                head=delete_front(head);
                cnt++;
            }
            else
            {
                head=head->next;
                cnt1++;
            }
        }
        //when head is equal to tail
        if(head->mango>head->next->mango)
        {
            head=delete_front(head);
            cnt++;
        }
        else
        {
            head=head->next;
            cnt1++;
        }
    }
        printf("Mangoes remaining\n");
        display(head);
        printf("\nMangoes fell %d\n",cnt);
        printf("\nMangoes remaining %d\n",cnt1);
}

void display(NODE head)
{
    NODE cur=head;
    if(head==NULL)
        printf("Mangoes list is empty\n");
        else
        {
            do
            {
                printf("%d\t",cur->mango);
                cur=cur->next;
            }while(cur!=head);
        }
}


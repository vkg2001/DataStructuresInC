#include <stdlib.h>
#include<stdio.h>
typedef struct node
{
    int data;
    struct node *next;
}*List;

int count=0;
List create();
List insertrear(List,int);
void display(List);
List insertatpos(List first,int item,int pos);
List deletefront(List head);

int main()
{
    List L=NULL;
    int ele,ch,m,i;
        printf("Enter number of pilgrims\n");
        scanf("%d",&ch);
        for(i=0;i<ch;i++)
        {
                    printf("enter age of pilgrim\n");
                    scanf("%d",&ele);
                    if(count==0)
                        L=insertrear(L,ele);
                    else
                    {
                        if(L->data<ele)
                        {
                          m=count/2;
                          L=insertatpos(L,ele,m);
                        }
                        else
                            L=insertrear(L,ele);
                    }
        }
    display(L);
    printf("\nEnter no. of pilgrims worshiped\t");
    scanf("%d",&m);
    for(i=0;i<m;i++)
    {
        L=deletefront(L);
    }
    printf("Pilgrims yet to worship in queue are\n");
    display(L);
    return 0;
}

List create()
{
    List x;
    x=malloc(sizeof(struct node));
    count++;
    x->next=NULL;
    return x;
}

List insertrear(List L,int x)
{
    List temp,p=L;
    temp=create();
    temp->data=x;
    if(L==NULL)
    {
        L=temp;
    }
    else
    {
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=temp;
    }
    return L;
}

void display(List L)
{
    if(L==NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        while(L!=NULL)
        {
            printf("%d ",L->data);
            L=L->next;
        }
    }
}

List deletefront(List head)
{
    if(head==NULL)
        printf("No one present\n");
    else
    {
        List cur=head;
        printf("Pilgrim worshiped age is : %d\n",head->data);
        head=head->next;
        free(cur);
    }
    return head;
}

List insertatpos(List first,int item,int pos)
{

    List t,prev,cur;
    int c=0;
    t=create( );
    t->data=item;
    cur=first;
    prev=NULL;
    if(pos==0)
    {
        first->next=t;
        //return first;
    }
    else
    {
    while(cur->next!=NULL && c!=pos)
    {
        c++;
        prev=cur;
        cur=cur->next;
    }
    prev->next=t;
    t->next=cur;
    }
    return first;
}

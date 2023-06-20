#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}*NODE;

void sortedinsert(NODE *H[],int x)
{
    NODE t,first,q=NULL,p=H;
    t=(NODE)malloc(sizeof(struct node));
    t->data=x;
    t->next=NULL;

    if(H==NULL)
        H=t;
    else
    {
        while(p&&p->data<x)
        {
            q=p;
            p=p->next;
        }
        if(p==first)
        {
            t->next=first;
            first=t;
        }
        else
        {
            t->next=q->next;
            q->next=t;
        }
    }
}
NODE search(NODE p,int key)
{
    while(p!=NULL)
    {
        if(key==p->data)
            return p;
        p=p->next;
    }
    return NULL;
}

int hash(int key)
{
    return key%10;
}

void insert(NODE H[],int key)
{
    int index=hash(key);
    sortedinsert(&H[index],key);
}
int main()
{
    NODE HT[10],temp;
    for(int i=0;i<10;i++)
        HT[i]=NULL;
        insert(HT,12);
        insert(HT,22);
        insert(HT,42);

        temp=search(HT[hash(22)],22);
        printf("%d ",temp->data);

        return 0;
}

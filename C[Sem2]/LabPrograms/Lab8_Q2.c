#include<stdio.h>
#include<stdlib.h>

struct birthday
{
    int candle;
    struct birthday *next;
    struct birthday *prev;
};

typedef struct birthday *NODE;

NODE getnewnode();
NODE insert_end(NODE head);
NODE blown_candle(NODE head);

int main()
{
    NODE head=NULL;
    int n;
    printf("Enter age:\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        head=insert_end(head);
    }
    head=blown_candle(head);
    return 0;
}

NODE getnewnode()
{
    NODE newn=(NODE)malloc(sizeof(struct birthday));
    if(newn==NULL)
    {

        printf("Memory not allocated\n");
        exit(0);
    }
    else
    {
        scanf("%d",&newn->candle);

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

NODE blown_candle(NODE head)
{
    int highest=head->candle;
    int cnt=1;
    NODE cur=head->next;
    do
    {
        if(cur->candle==highest)
        {
            cnt++;
        }
        else if(cur->candle>highest)
        {
            highest=cur->candle;
            cnt=1;
        }
        cur=cur->next;
    }while(cur!=head);
    printf("Number of candles blown are %d\n",cnt);
    printf("Candle number blown is %d\n",highest);
    return head;
}

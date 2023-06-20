#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int num;
    struct node *link;
}*NODE;

NODE create();
NODE insert_front_csll(NODE );
NODE insert_end_csll(NODE );
void display_csll(NODE );
NODE delete_front_csll(NODE );
NODE delete_end_csll(NODE );
NODE insert_pos_csll(NODE );
NODE delete_pos_csll(NODE );

int main()
{
   NODE start=NULL;
    int ch;
    while(1)
    {
        printf("\n----Circular Singly Linked List-----\n");
        printf("1:Insert Front. 2:Insert End. 3:Delete front. 4:Delete End. 5:Insert at  Position. 6:Delete from position. 7:Display. 8:Exit\nEnter Choice:\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: start=insert_front_csll(start);
                    break;
            case 2: start=insert_end_csll(start);
                    break;
            case 3: start=delete_front_csll(start);
                    break;
            case 4: start=delete_end_csll(start);
                    break;
            case 5: start=insert_pos_csll(start);
                    break;
            case 6: start=delete_pos_csll(start);
                    break;
            case 7: display_csll(start);
                    break;
            case 8: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}

NODE create()
{
    NODE temp;
    temp=(NODE *)malloc(sizeof(NODE));
    printf("Enter number\n");
    scanf("%d",&temp->num);
    temp->link=temp;
    return temp;
}

NODE insert_front_csll(NODE start)
{
    NODE temp, cur;
    temp=create();
    if(start==NULL)
    {
        start=temp;
        start->link=start;
    }
    else
    {
        cur=start;
        while(cur->link != start)
        {
            cur=cur->link;
        }
        cur->link=temp;
        temp->link=start;
        start=temp;
    }
    return start;
}

NODE insert_end_csll(NODE start)
{
    NODE temp=create();
    NODE cur;
    if(start==NULL)
    {
        start=temp;
        start->link=start;
    }
    else
    {
        cur=start;
        while(cur->link!=start)
        {
            cur=cur->link;
        }
        cur->link=temp;
        temp->link=start;
    }
    return start;
}

void display_csll(NODE start)
{
    NODE cur;
    if(start==NULL)
        printf("Circular List Empty\n");
    else if(start->link==start)
    {
        printf("start -> %d -> start", start->num);
    }
    else
    {
        cur=start;
        printf("\nstart->");
        while(cur->link != start)
        {
            printf("%d -> ",cur->num);
            cur=cur->link;
        }
        printf("%d -> start\n",cur->num);
    }
}

NODE delete_front_csll(NODE start)
{
    NODE cur, p;
    if(start== NULL)
        printf("Circular List is empty\n");
    else if(start->link == start)
    {
        printf("Deleted %d\n",start->num);
        free(start);
        start=NULL;
    }
    else
    {
        cur=start;
        p=start;
        while(cur->link != start)
        {
            cur=cur->link;
        }
        start=start->link;
        cur->link=start;
        printf("Deleted %d\n",p->num);
        p->link=NULL;
        free(p);
    }
    return start;
}

NODE delete_end_csll(NODE start)
{
    NODE prev, cur;
    if(start==NULL)
        printf("Circular list empty\n");
    else if(start->link == start)
    {
        printf("Deleted %d\n",start->num);
        free(start);
        start=NULL;
    }
    else
    {
        cur=start;
        prev=cur;
        while(cur->link != start)
        {
            prev=cur;
            cur=cur->link;
        }
        prev->link=start;
        cur->link=NULL;
        printf("Deleted %d\n",cur->num);
        free(cur);
    }
    return start;
}

NODE insert_pos_csll(NODE start)
{
    NODE temp=create();
    NODE cur, prev;
    int c=1,pos;
    if(start==NULL)
    {
        start=temp;
        temp->link=start;
    }
    else
    {
        printf("Enter node position: ");
        scanf("%d",&pos);
        if(pos==1)
        {
            cur=start;
            while(cur->link!=start)
            {
                cur=cur->link;
            }
            temp->link=start;
            cur->link=temp;
            start=temp;
        }
        else
        {
            cur=prev=start;
            while(c!=pos && cur->link!=start)
            {
                c++;
                prev=cur;
                cur=cur->link;
            }
            if(c==pos && cur->link==start)
            {
                cur->link=temp;
                temp->link=start;
            }
            else if(pos>c)
            {
                printf("Position is greater than nodes in list\n");
            }
            else
            {
                prev->link=temp;
                temp->link=cur;
            }
        }
    }
    return start;
}

NODE delete_pos_csll(NODE start)
{
    NODE prev, cur, ptr;
    int pos,c;
    if(start==NULL)
    {
        printf("Circular List is Empty\n");
    }
    else
    {
        printf("Enter position of node: ");
        scanf("%d",&pos);
        if(pos==1 && start->link==start)
        {
             printf("Deleted %d\n", start->num);
             free(start);
             start=NULL;
        }
        else if(pos==1)
        {
            ptr=start;
            printf("Deleted %d\n", ptr->num);
            cur=start;
            while(cur->link!=start)
            {
                cur=cur->link;
            }
            start=start->link;
            cur->link=start;
            free(ptr);
        }
        else
        {
            c=1;
            prev=cur=start;
            while(c!=pos && cur->link!=start)
            {
                c++;
                prev=cur;
                cur=cur->link;
            }
            if(pos>c)
            {
                printf("Position greater than nodes in list\n");
            }
            else
            {
                prev->link=cur->link;
                printf("Deleted %d\n", cur->num);
                free(cur);
            }
        }
    }
    return start;
}

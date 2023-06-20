#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct baggage
{
    char id[10],name[20],s[20],d[20];
    float weight;
    struct baggage *next;
};

typedef struct baggage *NODE;

NODE getnode();
NODE insert_end(NODE head);
void display(NODE head);
void display_luggage(NODE head,char sid[]);;
NODE delete_luggage(NODE head,char did[]);
void maxdur(NODE head);
void year(NODE head,int syear);

int main()
{
    int n;
    char sid[10],did[10];
    NODE head=NULL;
    printf("Enter number of luggages\n");
    scanf("%d",&n);
    printf("Enter luggage ID, name, source, destination & weight\n");
    for(int i=0;i<n;i++)
    {
        head=insert_end(head);
    }
    printf("Enter luggage ID to search and display\n");
    scanf("%s",sid);
    printf("Enter luggage ID to delete\n");
    scanf("%s",did);
    display(head);
    display_luggage(head,sid);
    printf("\n");
    head=delete_luggage(head,did);
    display(head);
    maxdur(head);
    return 0;
}

NODE getnode()
{
    NODE newn=(NODE)malloc(sizeof(struct baggage));
    if(newn==NULL)
    {
        printf("Memory not allocated\n");
        exit(0);
    }
    scanf("%s%s%s%s%f",newn->id,newn->name,newn->s,newn->d,&newn->weight);
    newn->next=newn;
    return newn;
}

NODE insert_end(NODE head)
{
	NODE newn,cur=head;
	newn=getnode( );
	if(head==NULL)
      	{
        return newn; //head=newn;
    	}
	else
    	{
            while(cur->next!=head)
                cur=cur->next;
            cur->next=newn;
            newn->next=head;
       	}
	return head;
}

void display(NODE head)
{
    NODE cur=head;
    if(head==NULL)
    {
        printf("Luggage list is empty");
    }
    else
    {
        printf("Luggage ID, name, source, destination & weight\n");
        do
        {
            printf("%s %s %s %s %0.2f\n",cur->id,cur->name,cur->s,cur->d,cur->weight);
            cur=cur->next;
        }while(cur!=head);
    }
}

void display_luggage(NODE head,char sid[])
{
    NODE cur=head;
    int flag=0;
    if(head==NULL)
    {
        printf("Songs list is empty");
    }
    else
    {
        printf("\nLuggage details of %s\nLuggage ID, name, source, destination & weight\n",sid);
        do
        {
            if(strcmp(cur->id,sid)==0)
            {
                flag=1;
                printf("%s %s %s %s %0.2f\n",cur->id,cur->name,cur->s,cur->d,cur->weight);
            }
            cur=cur->next;
        }while(cur!=head);
        if(flag==0)
            printf("No luggages found");
    }
}

NODE delete_luggage(NODE head,char did[])
{
    NODE cur=head,prev=NULL;
    if(head==NULL)
    {
        printf("Luggage list is empty");
    }
    else if(head->next==head)
    {
        if(strcmp(head->id,did)==0)
        {
            printf("\nDeleted %s %s %s %s %0.2f",head->id,head->name,head->s,head->d,head->weight);
            free(head);
            head=NULL;
        }
    }
    else if(strcmp(head->id,did)==0)
    {
        while(cur->next!=head)
        cur=cur->next;
    prev=head;
    cur->next=head->next;
    head=head->next;
    printf("\nDeleted %s %s %s %s %0.2f",prev->id,prev->name,prev->s,prev->d,prev->weight);
    free(prev);
    }
    else
    {
        do
        {
            if(strcmp(cur->id,did)==0)
            {
                prev->next=cur->next;
                printf("\nDeleted %s %s %s %s %0.2f",head->id,head->name,head->s,head->d,head->weight);
                free(cur);
                break;
            }
            prev=cur;
            cur=cur->next;
        }while(cur!=head);
    }
    return head;
}

void maxdur(NODE head)
{
    NODE cur=head,temp;
    float max=head->weight;
    if(head == NULL) {
        printf("Luggage list is empty");
    }
    else
        {
         do
         {
             if(max < cur->weight)
                {
                    max=cur->weight;
                    temp=cur;
                }
             cur= cur->next;
        }while(cur != head);

        printf("\nHighest weighed luggage is: %0.2f", max);
        printf("\n%s %s %s %s %0.2f",temp->id,temp->name,temp->s,temp->d,temp->weight);
    }
}

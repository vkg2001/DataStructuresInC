#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
typedef struct node *NODE;

NODE getnode()
{
	NODE temp;
	temp=malloc(sizeof(NODE));
	if(temp==NULL)
	{
		printf("NOT CREATED\n");
		exit(0);
	}
	temp->next = NULL;
	return temp;
}

void display(NODE head)
{
    NODE temp=NULL;
    if(head==NULL)
    {
        printf("EMPTY!\n");
    }
    else
    {
        temp=head;
        printf("head-> ");
        while(temp!=NULL)
        {
            printf("%d -> ",temp->data);
            temp=temp->next;
        }
        printf("NULL\n");
    }
}

NODE insert(int item,NODE head)
{
	NODE temp,cur;
	temp=getnode();
	temp->data=item;
	if(head==NULL)
	  return temp;
	cur=head;
	while(cur->next!=NULL)
	{
		cur=cur->next;
	}
	cur->next=temp;
	return head;
}

void remove_duplicate(NODE head)
{
    NODE cur=head,index=NULL,temp=NULL;
    if(head==NULL)
        {
        return;
        }
    else
        {
        while(cur!=NULL){
            temp=cur;
            index=cur->next;
            while(index!= NULL)
            {
                if(cur->data==index->data)
                {
                    temp->next=index->next;
                }
                else
                {
                    temp=index;
                }
                index=index->next;
            }
            cur=cur->next;
        }
    }
}

void main()
{
	NODE head=NULL;
	int choice,item;
	while(1)
	{
		printf("1.INSERT REAR\n2.DISPLAY\n3.REMOVE DUPLICATES [IF ANY]\n4.EXIT\n\nENTER CHOICE\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("ENTER ITEM TO BE INSERTED\n");
			        scanf("%d",&item);
			        head=insert(item,head);
			        break;
			case 2: printf("DISPLAY\n");
			        display(head);
			        break;
            case 3: printf("REMOVE DUPLICATE\n");
			        remove_duplicate(head);
			        break;
            case 4: printf("END\n");
                    exit(0);
			        break;
            default:printf("INVALID CHOICE!\n");
		}
	}
}

#include<stdlib.h>
#include<stdio.h>

typedef struct emp
{
	char name[25],gender[5];
	int id,age;
	struct emp *next;
}*NODE;
NODE getnode();
NODE read_details();
NODE insert_rear(NODE head);
NODE insert_front(NODE head);
NODE merged_list(NODE head,NODE sec);
NODE reverse_list(NODE head);
void display_list(NODE head);
void sort_descending(NODE head);
void remove_duplicate(NODE head);

int main()
{
    NODE head=NULL,first=NULL,second=NULL;
    int choice;
    for(;;)
    {
        printf("1.CREATE NODE\t2.DISPLAY\t3.SORT DESCENDING\t4.INSERT LEAST AGED\t5.INSERT MOST AGED\n");
        printf("6.SPLIT TWO PARTS\t7.SPLIT ALTERNATIVE INTO TWO\t8.ADD NEW LIST\t9.MERGE TWO LISTS\t10.REVERSE LIST\n");
        printf("11.NO. EMPLOYEES ABOVE 50\t12.DELETE DUPLICATE\t13.SWAP ALTERNATE EMP\t14.EXIT\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("ENTER ID, NAME, AGE, TYPE:\t");
                    head=insert_rear(head);
                    break;
            case 2: printf("DETAILS ARE:\n");
                    display_list(head);
                    break;
            case 3: sort_descending(head);
                    display_list(head);
                    break;
            case 4: printf("ENTER ID, NAME, AGE, TYPE:\t");
                    head=insert_front(head);
                    break;
            case 5: printf("ENTER ID, NAME, AGE, TYPE:\t");
                    head=insert_rear(head);
                    break;
            case 6:
                    break;
            case 7:
                    break;
            case 8: printf("CONTENT TO BE ADDED IN NEW LIST:\n");
                    second=insert_front(second);
                    break;
            case 9: printf("MERGED LIST:\n");
                    head=merged_list(head,second);
                    break;
            case 10:printf("REVERSE LIST:\n");
                    head=reverse_list(head);
                    break;
            case 11:
                    break;
            case 12:remove_duplicate(head);
                    break;
            case 13:
                    break;
            case 14: exit(0);
            default: printf("INVALID CHOICE");
                    break;
        }
    }
}

NODE getnode()
{
    NODE head;
    head=(NODE)malloc(sizeof(NODE));
    if(head==NULL)
    {
        printf("NOT CREATED");
        exit(0);
    }
    head->next=head;
    return head;
}

NODE read_details()
{
    NODE temp;
    temp=getnode();
    scanf("%d%s%d%s",&temp->id, temp->name, &temp->age, temp->gender);
    return temp;
}

NODE insert_front(NODE head)
{
	NODE new, cur=head;
	new = read_details();
	if(head==NULL)
    	{
            		head = new;
            		new -> next = head;
            		return head;
    	}
    	while(cur ->next != head)
       	{
		cur = cur -> next;
        }
      	cur -> next=new;
      	new->next=head;
        head = new;
    	return head;
}

NODE insert_rear(NODE head)
{
	NODE new, cur=head;
	new = read_details( );
	if(head == NULL)
      	{
	 	new->next=new;
        		return new;
    	}
	else
    	{
           		while(cur -> next != head)
          			cur =cur -> next;
       	}
    	cur -> next = new;
    	new -> next = head;
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
                if(cur->id==index->id)
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

void display_list(NODE head)
{
    NODE cur;
    if(head==NULL)
    {
        printf("LIST IS EMPTY\n");
        exit(0);
    }
    cur=head;
    while(cur->next!=head)
    {
        printf("%d\t%s\t%d\t%s\n",cur->id,cur->name,cur->age,cur->gender);
        cur=cur->next;
    }
    printf("%d\t%s\t%d\t%s\n\n",cur->id,cur->name,cur->age,cur->gender);
}

void sort_descending(NODE head)
{
    NODE cur=head,index=NULL,temp;
        if(head==NULL)
            {
                return;
            }
        else
        {
            while(cur!=NULL)
            {
                index=cur->next;
                while(index!=NULL)
                    {
                        if(cur->id<index->id)
                        {
                            temp=cur;
                            cur=index;
                            index=temp;
                        }
                        index = index->next;
                    }
                cur=cur->next;
            }
        }
}

NODE merged_list(NODE head,NODE sec)
{
    NODE cur;
    cur=head;
    while(cur->next!=NULL)
        cur=cur->next;
    cur->next=sec;
    return head;
}

NODE reverse_list(NODE head)
{
	NODE next_node,c,prev=NULL;
	c=head;
	while(c!=NULL)
        {
            next_node=c->next;
            c->next=prev;
            prev=c;
            c=next_node;
        }
    return prev;
}

void split_alternate(NODE head)
{
    NODE cur;
    if(head==NULL)
    {
        printf("LIST IS EMPTY\n");
        exit(0);
    }
    cur=head;
    while(cur->next=head)
    {
        if(cur)
        printf("%d\t%s\t%d\t%s\n",cur->id,cur->name,cur->age,cur->gender);
        cur=cur->next;
    }
    printf("%d\t%s\t%d\t%s\n\n",cur->id,cur->name,cur->age,cur->gender);
}

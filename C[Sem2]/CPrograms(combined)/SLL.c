#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct emp
{
	char name[25],gender[5];
	int id,age;
	struct emp *next;
}*NODE;

NODE getnode()
{
	NODE newn;
	newn=(NODE)malloc(sizeof(NODE));
	if(newn==NULL)
	{
		printf("Not created\n");
		exit(0);
	}
	newn->next = NULL;
	return newn;
}

NODE read_details()
{
    NODE temp;
    temp = getnode();
    printf("ENTER ID, NAME, AGE, GENDER:\t");
    scanf("%d %s %d %s",&temp->id, temp->name, &temp->age, temp->gender);
    return temp;
}

NODE insert_end(NODE head)
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
void display_list(NODE head)
{
    NODE cur;
    if(head == NULL)
    {
        printf("List is Empty\n");
        exit(0);
    }
    else
    {
        cur=head;
        printf("Details\n");
        printf("head-> ");
        while(cur->next!=head)
        {
            printf("%d %s %d %s -> ", cur->id, cur->name, cur->age, cur->gender);
            cur=cur->next;
        }
        printf("%d %s %d %s -> ", cur->id, cur->name, cur->age, cur->gender);
        printf("NULL\n");
    }
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

void remove_duplicate(NODE head)
{
    NODE cur=head,index=NULL,temp=NULL;
    if(head==NULL)
        {
        return;
        }
    else
        {
        while(cur!=NULL)
            {
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
int count(NODE head)
{
    NODE temp;
    temp = head;
    int count=0;
    if(temp == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        while(temp != NULL)
        {
            if(temp->age>50)
            {
                count++;
                temp = temp->next;
            }
        }
    }
    return count;
}
NODE reverse_list(NODE head)
{
	NODE next_node,cur,prev=NULL;
	cur=head;
	while(cur!=NULL)
	{
        next_node=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next_node;
	}
    return prev;
}

NODE merged_list(NODE head,NODE second)
{
    NODE cur;
    cur=head;
    while(cur->next!=NULL)
        cur=cur->next;
    cur->next=second;
    return head;
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
                        index=index->next;
                    }
                cur=cur->next;
            }
        }
}

int main()
{
    NODE head=NULL,second=NULL,rl;
    int choice,cnt;
    while(1)
    {
        printf("1.CREATE NODE\t2.DISPLAY\t3.SORT DESCENDING\t4.INSERT LEAST AGED\t5.INSERT MOST AGED\n");
        printf("6.SPLIT TWO PARTS\t7.SPLIT ALTERNATIVE INTO TWO\t8.ADD NEW LIST\t9.MERGE TWO LISTS\t10.REVERSE LIST\n");
        printf("11.NO. EMPLOYEES ABOVE 50\t12.DELETE DUPLICATE\t13.SWAP ALTERNATE EMP\t14.EXIT\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: head=insert_end(head);
                            break;
            case 2: printf("DETAILS ARE:\n");
                    display_list(head);
                            break;
            case 3: sort_descending(head);
                    display_list(head);
                            break;
            case 4: head=insert_front(head);
                            break;
            case 5: head=insert_end(head);
                            break;
            case 6:
            case 7: display_list(head);
                            break;
            case 8: printf("CONTENT TO BE ADDED IN NEW LIST:\n");
                    second=insert_end(second);
                            break;
            case 9: printf("MERGED LIST:\n");
                    head=merged_list(head,second);
                    break;
            case 10:printf("Reverse List \n");
			        rl=reverse_list(head);
			        display_list(rl);
                            break;
            case 11:cnt=count(head);
                    printf("Nos of nodes above 50 = %d\n",cnt);
                            break;
            case 12:remove_duplicate(head);
                    display_list(head);
                            break;
            case 13:remove_duplicate(head);
                    display_list(head);
                            break;
            case 14: exit(0);
                            break;
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}

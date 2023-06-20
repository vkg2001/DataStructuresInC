#include<stdio.h>
#include<stdlib.h>
struct candidate
{
	char name[25];
	int rank, age;
	char address[100];
	struct candidate *next;
};
/* A user-defined data type called “NODE” */
typedef struct candidate *NODE;

NODE insert_rear(NODE head);
NODE insert_front(NODE head);
NODE insert_pos(int pos,NODE head);
NODE getnode();

NODE read_details();

NODE delete_end(NODE head);
NODE delete_front(NODE head);
//NODE delete_pos(int pos,NODE head);// try to write code for deleting a node at specified position.
void display_list(NODE head);
void main()
{
    int pos, choice;
    NODE head=NULL;
    for(;;)
    {
printf("********choose options from the below menu**********\n\n");
printf("1. Insert data at the beginning. \n 2. Insert data at the end. \n 3. Insert data at specified position. \n 4. Delete data at the beginning \n 5. Delete data at the end. \n 6. Display all the elements. \n 7.exit \n");
scanf("%d",&choice);
            switch(choice)
            {
                case 1: printf("Enter Candidate details\n");
                        head=insert_front(head);break;

                case 2: printf("Enter Candidate details\n");
                        head=insert_rear(head); break;

                case 3: printf("enter the position to be inserted\n");
                        scanf("%d", &pos);
                        head=insert_pos(pos,head); break;

                case 4: printf("first element deleted\n");
                        head=delete_front(head); break;

                case 5: printf("last element deleted\n");
                        head=delete_end(head); break;

                /*case 6: printf("enter position\n");
                        scanf("%d,&pos");
                        head=delete_pos(pos, head);break;*/

                case 6: printf("Display List\n");
                        display_list(head); break;
                default : exit(0);
            }

        }
}

NODE getnode()
{
	NODE new;
	new=(NODE)malloc(sizeof(struct candidate));
	if(new==NULL)
	{
		printf("Not created\n");
		exit(0);
	}
	new->next = NULL;
	return new;
}

NODE read_details()
{
    NODE temp;
    temp = getnode();
    scanf("%s %d %d %s",temp->name,&temp->rank,&temp->age,temp->address);
    return temp;
}

NODE insert_rear (NODE head)
{
	NODE new, cur;
	new = read_details();
	new ->next = NULL;
         	if(head==NULL)
	          return new;
	cur = head;
	while (cur->next != NULL)
	{
		cur = cur->next;
	}
	cur -> next = new;
     	return head;
}

NODE insert_front( NODE head)
{
	NODE new;
	new = read_details();
	new -> next = NULL;
	if(head == NULL)
	{
  		return new;
	}
	new ->next = head;
	head = new;
	return head;
}

void display_list(NODE head)
{
	NODE cur;
	if(head==NULL)
	{
		printf("Empty List\n");
		return;
	}
	printf("elements are\n");
	cur=head;
	printf("Name\tRank\tAge\tAddress\n");
	while(cur!=NULL)
	{
		printf("%s\t%d\t%d\t%s\n",cur->name,cur->rank,cur->age,cur->address);
		cur= cur->next;
	}
	printf("\n");
}

NODE delete_end(NODE head)
{
NODE prev, cur;
if(head==NULL)
{
	printf("List Empty\n");
	return head;
}
if(head->next==NULL)
{
  printf("Deleted: %s\n", head->name);
	free(head);
	return NULL;
}
prev =NULL;
 cur =head;
while(cur ->next != NULL)
{
	prev= cur;
	 cur = cur ->next;
}
printf("Deleted: %s\n", cur->name);
free(cur);
prev->next=NULL;
return head;
}

NODE delete_front (NODE head)
{
NODE cur;
if(head==NULL)
{
	printf("List Empty\n");
	return head;
}
cur=head;
head=head->next;
printf("Deleted: %s\n", cur->name);
free(cur);
return head;
}

NODE insert_pos(int pos, NODE head)
{
    NODE new, cur, prev;
    int count;
    new= read_details();
    new->next=NULL;
    if(head==NULL && pos==1)
        return new;
    if(head==NULL)
    {
        printf("invalid position\n");
        return head;
    }
    if(pos==1)
    {
        new->next=head;
        return new;
    }
    count=1;
    prev=NULL;
    cur=head;
    while(cur!=NULL &&count!=pos)
    {
        prev=cur;
        cur=cur->next;
        count++;
    }
    if(count==pos)
    {
        prev->next=new;
        new->next=cur;
        return head;
    }
    return head;
}

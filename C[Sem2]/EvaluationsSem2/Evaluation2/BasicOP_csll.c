//Insert Rear
//Display
//Insert front
//Del rear
//Del front
//Insert pos
//Delete pos
//Display middle_element
//Reverse list

#include<stdio.h>
#include<stdlib.h>
struct list
{
	int item;
	struct list *next;
};


/* A user-defined data type called “NODE” */
typedef struct list *NODE;
NODE getnode()
{
     NODE new;
    new=malloc(sizeof(struct list));
    if(new==NULL)
    {  printf("Not created\n");
    exit(0);
    }
    printf("Enter item\n");
    scanf("%d",&new->item);
    new->next=new;
    return new;
}

NODE insert_end (NODE head)
{
	NODE new, cur;
	new = getnode() ;
	if(head == NULL)
      	{
	 	head=new;
        		return head;
    	}
	cur=head;

           		while(cur -> next != head)
          	{
		cur =cur -> next;
       	}
    	cur -> next = new;
    	new -> next = head;
	return head;
}

void display_list(NODE head)
{
     NODE cur;
    if(head==NULL)
    { printf("Empty list\n");
       exit(0);
    }
    printf("elements are\n");
    cur=head;
    printf("elements in the list\n");
    while(cur->next!=head)
    {   printf("%d\t",cur->item);
         cur=cur->next;
          }
    printf("%d\t",cur->item);
    printf("\n");
}

void display_middle_element(NODE head)
{
    NODE fast=head;
    NODE slow=head;

    if(head==NULL)
    {
        printf("Empty list\n,No middle element found\n");
       return;
    }
    while(fast!=NULL&&fast->next!=head)
    {   if(fast->next->next==head)
          break;

        fast=fast->next->next;
        slow=slow->next;

    }
    printf("Middle element=%d\n",slow->item);
    }
    void reverseList(NODE head)
    {
        NODE prev,cur,n,last;

        if(head == NULL)
        { printf("List empty\n");
        }

    last=head;
    prev=head;
    cur=head;
    cur=cur->next;
    last=last->next->next;
            while(cur!=head)
            {
             //   head = head->next;
                cur->next = prev;

                prev = cur;
                //cur = head;
                cur=last;
                last=last->next;

            }
    // Make last node as head

            head = prev;
            cur->next=head;
    display_list(head);
            printf("SUCCESSFULLY REVERSED LIST\n");
}



NODE insert_front (NODE head)
{
	NODE new, cur;
	new = getnode();
	if (head ==NULL)
    	{
            		head = new;
            		return head;
    	} cur=head;
    	while(cur ->next != head)
       	{
		cur = cur -> next;
        	}
      	new->next=head;
    cur -> next=new;
    head = new;
            return head;
}

NODE delete_end (NODE head)
{
     NODE prev, cur;
     // CASE 1: When list is empty
     if(head ==NULL)
     {
 	printf("List empty\n");
	return head;
     }
  //CASE 2: When list contains only one node
     if(head->next==head)
     {
         printf("Item deleted: %d\n", head->item);
         free(head);
          head=NULL;
         return  head;
     }
        // CASE 3: When multiple nodes present
     cur = head;prev=NULL;
     while(cur -> next != head)
     {
     	prev=cur;
	cur=cur->next;
     }
     prev->next=head;
     printf("Item deleted: %d\n",cur->item);
     free(cur);
     return head;
}

NODE delete_front (NODE head)
{
     NODE temp, cur=head;
     if(head==NULL)
	  {
         printf("List empty\n");
	      return NULL;
	  }
	  if(head->next==head)  //single node
	  {
	      printf("Deleted item: %d\n",head->item);
	      free(head);
	      return NULL;
	  }
while(cur->next != head)
	{
          		cur=cur->next;
	}
   	temp=head;
   	head=temp->next;
	cur->next=head;
	printf("Deleted item: %d\n",temp->item);
	free(temp);
	return head;
}

NODE insert_pos(NODE head,int pos)
{

    NODE ptr,prev,cur,newnode;

    int i=1,count=1;
    if(head==NULL)
    {
        printf("List is empty,can not enter te data at this place\n");
        return head;
    }

    ptr=head;
    while(ptr->next!=head)// count the number of nodes
    {
        ptr=ptr->next;
        count++;
    }
    count++;

    if(pos>count)
    {
        printf("list containd %d nodes, can not insert at %d",count,pos);
        return head;
    }
    cur=head;
    newnode=getnode();
    newnode->next=newnode;
    while(i<pos)
    {
        prev=cur;
        cur=cur->next;
        i++;
    }

       newnode->next=cur;
       prev->next=newnode;
    return head;
}

NODE delete_pos(NODE head,int pos)
{
    NODE prev,c,t;
   /* if(head==NULL)
    {
        printf("List empty\n No node to delete\n");
    return h;

    }*/
    if(head->next==head)
    {
        printf("Element to be deleted=%d\n",head->item);
        free(head);
        return NULL;
    }
    else if(pos==1)
            head=delete_front(head);
      else
        {
        c=head;
        int count=1;
        while(c->next!=head && pos!=count)
        {
            prev=c;
            c=c->next;
            count++;
        }
        if(pos>count)
        {
            printf("\nlist contains %d elements, cant delete at %d position\n",count,pos);
        }
        else
        {
            prev->next=c->next;
            free(c);
        }
        }
        return head;
}

int main()
{
	NODE head = NULL;
	int choice,pos,data;
	for(;;)
	{
		printf("\n1-Insert Rear\n2-Display\n3-Insert front\n4.-Del rear\n5- Del front\n6- Insert pos\n 7- Delete pos\n8- Display middle_element\n 9:-Reverse list\n10:Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("Enter Items to be inserted in the list\n");
			           head=insert_end(head);
                    break;
			case 2: printf("Display List Inserted\n");
                        display_list(head);
                        break;
			case 3 :
                    printf("Enter Items to be Inserted\n");
                    head=insert_front(head);
                    break;

			case 4:
                    printf("Rear element delete\n");
                    head=delete_end(head);
                    break;
			case 5:
                    printf("front element delete\n");
                    head=delete_front(head);
                    break;
            case 6: printf("enter item position to be inserted\n");
                    scanf("%d",&pos);
                    head=insert_pos(head,pos);
                    break;
        case 7: printf("enter position to be deleted\n");
                    scanf("%d",&pos);
                    head=delete_pos(head,pos);
                    break;

        case 8:printf("Display middle element in the list\n");
            display_middle_element(head);
            //printf("middle of the list is = %d\n",slow->item);
                        break;
        case 9:printf("Reversed list\n");
                                reverseList(head);
                               // display_list(head);
                                break;


        default: exit(0);
		}
	}

}

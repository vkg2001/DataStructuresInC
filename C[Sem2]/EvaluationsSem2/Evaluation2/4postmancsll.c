#include<stdio.h>
#include<stdlib.h>

struct letter
{
	char name[25];
	int hno;
	char area [100];
    long int mobileno;
	struct letter *next;
};
/* A user-defined data type called “NODE” */
typedef struct letter *NODE;


NODE getnode()
{
	NODE newn;
	newn=(NODE)malloc(sizeof(struct letter));
	if(newn==NULL)
	{
		printf("Not created\n");
		exit(0);
	}
	newn->next = newn;
	return newn;
}

NODE read_details()
{
    NODE temp;
    temp=getnode();
    printf("Enter name, house number, area, mobile number.\n ");
    scanf("%s%d%s%ld",temp->name, &temp->hno, temp->area, &temp->mobileno);
    return temp;
}

NODE insert_end (NODE head)
{
	NODE newn, cur=head;
	newn = read_details( );
	if(head == NULL)
      	{
        		return newn;
    	}
	else
    	{
           		while(cur -> next != head)
                        cur =cur -> next;
       	}
    	cur -> next = newn;
    	newn -> next = head;
	return head;
}

NODE insert_front (NODE head)
{
	NODE newn, cur=head;
	newn = read_details();
	if (head ==NULL)
    	{
            		return newn;
    	}
    	while(cur ->next != head)
       	{
            cur = cur -> next;
        }
      	newn->next=head;
        cur -> next=newn;
        head = newn;
    	return head;
}

void display_list(NODE head)
{
    NODE cur=NULL;
    if(head == NULL)
    {
        printf("\nPostman's List is Empty\n");
    }
    else if(head->next == head)
    {
        printf("House details\n");
        printf("Name House No. Area Mobile no.\n");
        printf("head-> ");
        printf("%s %d %s %ld -> ", head->name, head->hno, head->area, head->mobileno);
            printf("head\n");
    }
    else
    {
        cur=head;
        printf("House details\n");
        printf("Name House No. Area Mobile no.\n");
        printf("head-> ");
        while(cur ->next != head)
        {
            printf("%s %d %s %ld -> ", cur->name, cur->hno, cur->area, cur->mobileno);
            cur = cur->next;
        }
        printf("%s %d %s %ld -> ", cur->name, cur->hno, cur->area, cur->mobileno);
        printf("head\n");
    }
}

NODE delete_end(NODE head)
{
    NODE prev=NULL, cur=head;
    if(head==NULL)
    {
        printf("Postman list is empty\n");
        return NULL;
    }
    else if(head->next == head) // single node
    {
        printf("House no deleted = %d\n", head->hno);
        free(head);
        return NULL;
    }
    else
    {
        while(cur->next != head)
        {
            prev = cur;
            cur = cur->next;
        }
        prev->next = head;
        printf("House no deleted = %d\n", cur->hno);
        cur->next = cur;
        free(cur);
    }
    return head;
}

NODE delete_front(NODE head)
{
    NODE cur=head, temp=head;
    if(head == NULL)
    {
        printf("Postman list is empty\n");
        return NULL;
    }
    else if(head->next == head) // single node
    {
        printf("House no deleted = %d\n", head->hno);
        free(head);
        return NULL;
    }
    else
    {
        while(cur->next != head)
        {
            cur = cur->next;
        }
        head=head->next; // shifting head pointer to second node.
        cur->next = head; // connecting last node to second node(new first node).
        printf("House no deleted = %d\n", temp->hno);
         free(temp);
    }
    return head;
}

NODE insert_after(NODE head)
{
    int house;
    NODE cur=head, prev = NULL;
    NODE newn = read_details();
    if(head == NULL)
    {
        return newn;
    }
    printf("Enter house number after which you want enter the details\n");
    scanf("%d", &house);
    if(head->next == head && head->hno == house)
    {
        head->next = newn;
        newn->next = head;
        return head;
    }
    else if(head->hno == house)
    {
          cur = head->next; // cur points to 2nd node
          head->next = newn;
          newn->next = cur;
        return head;
    }
    else
    {
        while (cur->next != head)
        {
            if(cur->hno == house)
                break;
            else
            {
                prev = cur;
                cur = cur->next;
            }
        }
        if(cur->hno == house)
        {
            prev = cur;
            cur = cur->next;
            prev->next = newn;
            newn->next = cur;
        }
        else
            printf(" House number %d does not exist in the list\n", house);
    }
    return head;
}

int main()
{
    NODE head=NULL;
    int ch;
    printf("\n--- POST MAN LETTERS DELIVERY ---\n");
    while(1)
    {
        printf("Menu -- 1. Insert End. 2. Insert Front 3. Delete End. 4. Delete front. 5. Insert After. 6. Display. 7. Exit.\nEnter choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: head = insert_end(head);
                            break;
            case 2: head = insert_front(head);
                            break;
            case 3:  head= delete_end(head);
                            break;
            case 4: head=delete_front(head);
                            break;
            case 5: head= insert_after(head);
                            break;
            case 6: display_list(head);
                            break;
            case 7: exit(0);
                            break;
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}

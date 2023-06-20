//insert_end
//insert_front
//insert_before
//display_list
//delete_front
//delete_end
//delete_specific
//count
//reverse_list

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct candidate
{
    char name[25];
    int rank, age;
    char addr[20];
    struct candidate *next; // link part to store the address of next node.
};

typedef struct candidate *NODE;

NODE getnode()
{
	NODE newn;
	newn=(NODE)malloc(sizeof(struct candidate));
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
    printf("Enter name, rank, age, address\n");
    scanf("%s %d %d %s",temp->name,&temp->rank,&temp->age,temp->addr);
    return temp;
}

NODE insert_end(NODE head)
{
    NODE newn=NULL, cur=NULL;
    newn = read_details();
    if(head == NULL)
    {
        return newn;
    }
    else
    {
        cur=head;
        while(cur->next != NULL)
            cur = cur->next;
        cur->next = newn;
    }
    return head;
}

void display_list(NODE head)
{
    NODE cur=NULL;
    if(head == NULL)
    {
        printf("Candidate List is Empty\n");
    }
    else
    {
        cur=head;
        printf("candidate details\n");
        printf("Name Rank Age Address\n");
        printf("head-> ");
        while(cur != NULL)
        {
            printf("%s %d %d %s -> ", cur->name, cur->rank, cur->age, cur->addr);
            cur = cur->next;
        }
        printf("NULL\n");
    }
}

NODE insert_front(NODE head)
{
    NODE newn;
    newn = read_details();
    if(head == NULL)
    {
        return newn;
    }
    newn->next = head;
    head = newn;
    return head;
}

NODE insert_before(NODE head)
{
    char nm[20];
    NODE cur = head, prev = NULL;
    NODE newn = read_details();
    if(head == NULL)
    {
        return newn;
    }
    printf("Enter name of candidate before which you need to enter the details\n");
    scanf("%s", nm);
    while (cur -> next != NULL)
    {
        if(strcmp(cur->name, nm)==0)
        {
            break;
        }
        else
        {
            prev = cur;
            cur = cur->next;
        }
    }
    prev->next = newn;
    newn->next = cur;

    return head;
}

NODE delete_end(NODE head)
{
    NODE prev = NULL, cur = head;
    if(head == NULL)
    {
        printf("Candidate List is Empty\n");
    }
    if(head->next == NULL)
    {
        printf("Deleted = %s\n",head->name);
        free(head);
        return NULL;
    }
    while(cur-> next != NULL)
    {
        prev = cur;
        cur = cur->next;
    }
    printf("Deleted = %s\n",cur->name);
    prev->next = NULL;
    free(cur);

    return head;
}

NODE delete_front(NODE head)
{
    NODE cur=head;
    if(head == NULL)
    {
        printf("Candidate List is Empty\n");
    }
    head = head->next;
    printf("Deleted = %s\n", cur->name);
    cur->next = NULL;
    free(cur);

    return head;
}

NODE delete_specific(NODE head)
{
    NODE prev=NULL, cur=head;
    char nm[20];
    printf("Enter name of student whose details has to be deleted?\n");
    scanf("%s",nm);
    if(head == NULL)
    {
        printf("Candidates List is Empty\n");
    }
    if(head->next == NULL && strcmp(head->name, nm)==0)
    {
        printf("Deleted candidate = %s\n", head->name);
        free(head);
        return NULL;
    }
    if(strcmp(head->name, nm)==0)
    {
        cur=head;
        head = head->next;
        free(cur);
        return head;
    }
    while(cur->next != NULL)
    {
        if(strcmp(cur->name, nm)==0)
        {
            break;
        }
        else
        {
            prev= cur;
            cur= cur->next;
        }
    }
    prev->next = cur->next;
    printf("Deleted Candidate = %s\n", cur->name);
    free(cur);
    return head;
}
int count(NODE head)
{
    NODE temp;
    temp = head;
    int cnt=0;
    if(temp == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        while(temp != NULL)
        {
            cnt++;
            temp = temp->next;
        }
    }
    return cnt;
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


int main()
{
    NODE head=NULL;
    int ch,cnt;
    while(1)
    {
        printf("Menu -- 1. Insert End. 2. Insert Front 3. Insert before 4. Delete End 5. Delete Front 6. Delete Specific 7. Display. 8. count . 9.Exit.10.reverse.11.split\nEnter choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: head = insert_end(head);
                            break;
            case 2: head = insert_front(head);
                            break;
            case 3: head=insert_before(head);
                            break;
             case 4: head = delete_end(head);
                            break;
             case 5: head=delete_front(head);
                            break;
            case 6: head = delete_specific(head);
                            break;
             case 7: display_list(head);
                            break;
            case 8: cnt = count(head);
                    printf("Nos of nodes = %d\n",cnt);
                    break;
            case 9: exit(0);
                    break;
            case 10:printf("Reverse List \n");
			        head=reverse_list(head);
			        display_list(head);
			        break;

            default: printf("Invalid choice\n");
        }
    }
    return 0;
}

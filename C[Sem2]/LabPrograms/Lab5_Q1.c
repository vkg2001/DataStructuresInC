#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct cprogram
{
	char name[25],id[20],place[10];
	float sgpa;
	struct cprogram *next;
};

typedef struct cprogram *NODE;

NODE getnode()
{
    NODE new;
    new=(NODE)malloc(sizeof(struct cprogram));
    if(new==NULL)
    {
        printf("NOT CREATED\n");
        exit(0);
    }
    new->next=new;
    return new;
}

NODE read_details()
{
    NODE temp;
    temp=getnode();
    scanf("%s%s%s%f",temp->id, temp->name, temp->place, &temp->sgpa);
    return temp;
}

NODE insert_end (NODE head)
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

void display(NODE head)
{
    NODE cur;
    if(head==NULL)
    {
        printf("LIST EMPTY\n");
        exit(0);
    }
    cur=head;
    printf("head   ->  ");
    while(cur->next!=head)
    {
        if(cur->next==NULL)
        {
            return;
        }
        else
        printf("%s\t%s\t%s\t%0.2f  ->  ",cur->id,cur->name,cur->place,cur->sgpa);
        cur=cur->next;
    }
    printf("%s\t%s\t%s\t%0.2f",cur->id,cur->name,cur->place,cur->sgpa);
    printf("\n");
}

NODE less(NODE head)
{
    NODE head2=NULL;
    head2=getnode();
    NODE temp=head->next,ptr2=head2;
    NODE nn=NULL;
    do
    {
        if (temp->sgpa < 4.0)
        {
            nn=getnode();
            strcpy(nn->id, temp->id);
            strcpy(nn->name, temp->name);
            strcpy(nn->place, temp->place);
            nn->sgpa = temp->sgpa;

            ptr2->next = nn;
            nn->next = head2;
            ptr2 = nn;
        }

        temp=temp->next;
    } while (temp!=head);
    printf("LIST OF BELOW 4 SGPA:\n");
    display(head2);
    return head;
}
void count(NODE head)
{
    NODE cur;
    int count=0;
    float y=9.0;
    if(head==NULL)
    {
        printf("LIST EMPTY\n");
        return;
    }
    cur=head;
    while(cur->next!=head)
    {
        if(cur->sgpa>y)
            count++;
        cur=cur->next;
    }
    if(cur->sgpa>y)
        count++;
    printf("STUDENTS ABOVE 9 SGPA: %d\n\n",count);
}

int main()
{
    NODE head=NULL,temp=NULL;
    int choice,n;
    for(;;)
    {
        printf("1.ENTER DATA\t2.DISPLAY\t3.COUNT ABOVE 9 SGPA\t4.DISPLAY BELOW 4 SGPA\t5.EXIT\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("NO. OF STUDENTS:\n");
                scanf("%d",&n);
                printf("ENTER ID, NAME, PLACE & SGPA\n");
                for(int i=0;i<n;i++)
                {
                    head=insert_end(head);
                }
            break;
            case 2: printf("DISPLAY:\n");
            display(head);
            break;
            case 3: count(head);
            break;
            case 4: head=less(head);
            break;
            case 5: exit(0);
            break;
            default: printf("INVALID CHOICE!");
        }
    }
}


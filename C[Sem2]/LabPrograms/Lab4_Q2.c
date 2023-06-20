#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct team
{
    char name[25];
    int jersey_no;
    int player_score,age;
    struct team *next;
};

typedef struct team *NODE;

NODE getnode()
{
	NODE newn;
	newn=(NODE)malloc(sizeof(struct team));
	if(newn==NULL)
	{
		printf("NOT CREATED\n");
		return NULL;
	}
	newn->next = NULL;
	return newn;
}

NODE read_details()
{
    NODE temp;
    temp = getnode();
    printf("ENTER NAME, JERSEY NUMBER, SCORE & AGE:\n");
    scanf("%s %d %d %d",temp->name,&temp->jersey_no,&temp->player_score,&temp->age);
    return temp;
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
NODE delete_specific(NODE head)
{
    NODE prev=NULL, cur=head;
    int n;
    printf("ENTER WITH WHAT TO REPLACE?\n");
    scanf("%d",&n);
    if(head==NULL)
    {
        printf("LIST EMPTY\n");
    }
    if(head->next==NULL&&head->jersey_no==n)
    {
        printf("REMOVED PLAYER NUMBER= %d\n",head->jersey_no);
        free(head);
        return NULL;
    }
    if(head->jersey_no==n)
    {
        cur=head;
        head=head->next;
        free(cur);
        return head;
    }
    while(cur->next!=NULL)
    {
        if(head->jersey_no==n)
        {
            break;
        }
        else
        {
            prev=cur;
            cur=cur->next;
        }
    }
    prev->next = cur->next;
    printf("REMOVED PLAYER NUMBER= %d\n",head->jersey_no);
    free(cur);
    return head;
}

void display_list(NODE head)
{
    NODE cur=NULL;
    if(head == NULL)
    {
        printf("LIST EMPTY\n");
    }
    else
    {
        cur=head;
        printf("PLAYER DETAILS\n");
        printf("PLAYER NAME, JERSEY NUMBER, SCORE & AGE\n");
        printf("head-> ");
        while(cur != NULL)
        {
            printf("%s %d %d %d -> ",cur->name,cur->jersey_no,cur->player_score,cur->age);
            cur=cur->next;
        }
        printf("NULL\n");
    }
}
int main()
{
    NODE head=NULL;
    int ch;
    while(1)
    {
        printf("MENU -- 1.INSERT FRONT 2.DELETE END 3. DISPLAY LIST\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: head=insert_front(head);
                            break;
            case 2: head=delete_specific(head);
                            break;
            case 3: printf("LIST OF PLAYERS:\n");
                            display_list(head);
                            break;
            case 4: exit(0);
            default: printf("INVALID CHOICE!\n");
        }
    }
    return 0;
}

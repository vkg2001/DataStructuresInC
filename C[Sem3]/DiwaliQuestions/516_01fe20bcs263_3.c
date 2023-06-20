#include<stdio.h>
#include<stdlib.h>

struct prolific_potion
{
     char ingredient[30];
     int quantity;
     struct prolific_potion *prev;
     struct prolific_potion *next;
};
typedef struct prolific_potion *NODE;

NODE getnode();
NODE insert_end(NODE);
void display(NODE);
NODE delete_specific(NODE,char[]);

int main()
{
    NODE head=NULL;
    int choice,quantity;
    char data[25];
    printf("Enter 1 to Buy; 2 to Display; 3 to use Ingredient\n");
    scanf("%d",&choice);
     for(;;)
     {
         switch(choice)
         {
             case 1:head=insert_end(head);

             case 2:display(head);

             case 3: printf("enter the ingredient you want to use and its quantity\n");
                     scanf("%s%d",data,&quantity);
                     head=delete_specific(head,data[25]);
             }
     }
     return 0;
}

NODE getnode()
{
    NODE newnode = (NODE)malloc(sizeof(struct prolific_potion));
    if(newnode==NULL)
    {
    printf("DLL is empty");
    exit(0);
    }
       scanf("%s%d",newnode->ingredient[25],&newnode->quantity);
       scanf("%s%d",newnode->ingredient[25],&newnode->quantity);
       newnode->prev = NULL;
       newnode->next = NULL;
       return newnode;
}

NODE insert_end(NODE head)
{
   NODE cur = head;
   NODE newnode = getnode();
   if(head == NULL)
   head = newnode;
   else
{
    while(cur -> next != NULL)
       cur = cur -> next;
       cur -> next = newnode;
       newnode -> prev = cur;
}
       return head;
}

void display(NODE head)
{
     NODE cur = head;
   if(head == NULL)
        printf("\nDLL is empty\n");
     else
    {
        while(cur!= NULL)
        {
                printf("%s-%d\n",cur->ingredient,cur->quantity);
                cur = cur->next;
        }
    }
}

NODE delete_specific(NODE head,char data[25])
{
    NODE cur=head,back=NULL;
      if(head==NULL)
    {
        printf("List is empty\n");
     return head;
    }
      if(head->next==NULL)
    {
      if(strcmp(head->ingredient,data)==0)
    {
      printf("Deleted %s\n",head->ingredient);
      free(head);
      head=NULL;
     return head;
    }
    }
     if(head->next!=NULL)
{
    if(strcmp(head->ingredient,data)==0)
    {
    NODE temp=head;
    head=head->next;
    free(temp);
    return head;
    }
}
    while(cur->next!=NULL)
{
    if(strcmp(cur->ingredient,data)==0)
    break;
        back=cur;
        cur=cur->next;
}
    if(cur->next==NULL)
{
    if(strcmp(cur->ingredient,data)==0)
    {
        back->next=NULL;
        free(cur);
    return head;
    }
    else
    {
        printf("Unable to delete! Ingredient not found!\n");
    return head;
    }
}
    else
    {
        back->next=cur->next;
        cur->next->prev=back;
        free(cur);
    return head;
    }
}

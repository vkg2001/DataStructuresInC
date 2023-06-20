#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct employe
{
    char name[20];
    int age;
    int salary;
    int id;
    struct employe *next;

};
typedef struct employe *NODE;

NODE getnode()
{
    NODE n;
    n=(NODE)malloc(sizeof(struct employe));
    if(n==NULL)
    {
        printf("not creatde\n");
        //exit(0);
    }
    n->next=NULL;
    return n;
}
NODE read_details()
{
   NODE temp;
   temp=getnode();
   printf("enter name age salary id\n");
   scanf("%s%d%d%d",temp->name,&temp->age,&temp->salary,&temp->id);
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
    NODE fur=NULL;
    if(head == NULL)
    {
        printf("Candidate List is Empty\n");
    }


    else
    {
        fur=head;

        while(fur != NULL)
        {
            printf("%s\t%d\t%d\t%d\n",fur->name,fur->age,fur->salary,fur->id);
            fur = fur->next;
        }
        printf("\n");
    }
}
NODE insert_front(NODE head)
{    NODE nn;

nn=read_details();

    if(head==NULL)
    {
        head=nn;
        return head;
    }
    nn->next=head;
    head=nn;  /// compul head=nn;
   // nn=head;

    return head;
}
int count(NODE head)
{
    NODE cur=head;  int num=0;
    if(head==NULL)
    {
        printf("no node is present\n");

    }
    else
 {
      while(cur!=NULL)
    {
        num++;
        cur=cur->next;
    }


    }
        //printf("the number of nodes are %d\n",num);
        return num;
}
NODE delete_front(NODE head)
{
    NODE temp=head;
    NODE cur=head;


    if(head==NULL)
    {
        printf("delete successfull\n");

    }
    cur=cur->next;
    head=cur;
    temp->next=NULL;
    free(temp);
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
    printf("Deleted employe name :( is %s\n",cur->name);
    prev->next = NULL;
    free(cur);

    return head;

}


NODE insert_sort(NODE head)
{
    NODE temp=read_details();
    NODE cur=head, prev=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else if(head->age < temp->age)
    {
            temp->next=head;
            head=temp;
    }
    else
    {
        cur=head;
        prev=NULL;
        while(cur->age > temp->age && cur->next !=NULL)
         {
            prev=cur;
            cur=cur->next;
        }
        if(cur->next==NULL && cur->age > temp->age)
        {
            cur->next=temp;
        }
        else
        {
            prev->next=temp;
            temp->next=cur;
        }
    }
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

NODE merged_list(NODE head,NODE HEAD)
{
    NODE c,t;
    c=head;
    while(c->next!=NULL)
        c=c->next;
    c->next=HEAD;
    return head;
}

int age(NODE head)
{

    NODE cur=head;
int cc=0;
    if(head==NULL)
    {
        printf("no employed found \n");
        return 0;
    }
    while(cur!=NULL)
    {
        if(cur->age >50)
        {
            cc++;
        }
        cur=cur->next;
    }

    return cc;
}
NODE insert_before(NODE head)
{
    char nm[20];
    NODE newn=read_details();
    NODE prev=newn;
    NODE cur=head;
    if(head==NULL)
    {
      return newn;
    }
    printf("enter name before which list has to added\n");
    scanf("%s",nm);

   while(cur->next!=NULL)
   {
       if(strcmp(cur->name,nm)==0)
       {
           break;
       }
       else
        {  prev=cur;
       cur=cur->next;
        }
   }
    prev->next=newn;
    newn->next=cur;
   return head;
}


int main()
{ NODE head=NULL;
NODE HEAD=NULL;

int ch;
int cc=0;
int num;
while(1)
{
    printf("1.insert end 2.display 3.insert front 4.number of nodes 5.delete front 6.delete end 7.insert sort 8.delete specific 9.insert list 2 10.display list 2 11.merging lists 12.above 50 age list 13.insert before\n");
    scanf("%d",&ch);

    switch(ch)
    {
        case 1:head=insert_end(head);
          break;
          case 2:
              printf("*DISPLAYING EMPLOYEE DETAILS***\n");
              display_list(head);
          break;
          case 3: head=insert_front(head);
          break;
          case 4:num=count(head);

          printf("the number of nodes are %d\n",num);
          break;
          case 5:head=delete_front(head);
          break;
          case 6:head=delete_end(head);
          break;
          case 7:head=insert_sort(head);
          break;
          case 8: head=delete_specific(head);
          break;
          case 9: HEAD=insert_front(HEAD);
          break;
          case 10:printf("*DISPLAYING EMPLOYEE DETAILS of list 2.***\n");
                  display_list(HEAD);
          break;
          case 11: head=merged_list(head,HEAD);
          break;
          case 12:cc=age(head);
             printf("number of employess above 50 age are %d\n",cc);
          break;
          case 13: head=insert_before(head);
          break;

          default: printf("invalid choice\n");
    }
}
return 0;

}

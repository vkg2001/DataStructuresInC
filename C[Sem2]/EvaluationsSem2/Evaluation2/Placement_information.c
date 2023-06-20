/*1.	Chicago college Placement Officer Mr. Mahon Raj has all the details of the students who are placed
from the college along with the company name and passed out year. Since the ABN visit is in March 2021,
Placement Officer has two tasks. The first one displays the students who are placed in 2020 and
the second one displays the student details who has the highest Package. Please help Mr. Mahon Raj to do the tasks.*/

#include<stdio.h>
#include<stdlib.h>

typedef struct placed_student
{
     char sname[20],branch[20],cname[20];
   int year, package;

  struct placed_student *next;
}*node;

  node getnode();
  node read_details();

  node insert_rear(node head);
  node insert_front(node head);

  void display_list(node head);
  void display_year(node head);
  void display_highestpkg(node head);

  node delete_front(node head);
  node delete_rear(node head);

  main()
  {
      node head;
      head=NULL;

      int choice;

for(;;)
      {
          printf("\n1. insert\n2.Display\n3.Display year\n4.Display package\n5.insert front\n 6.delete front\n7.delete rear\n8.exit\n");
           scanf("%d",&choice);

           switch(choice)
           {
               case 1: printf("Enter details of student\n");
                head=insert_rear(head); break;

                case 2: printf("Display list\n");
                display_list(head);
                break;

                case 3: printf("Display list based on year 2020\n");
                display_year(head);break;

                case 4:printf("Display list with highest package\n");
                display_highestpkg(head);break;

                case 5:printf("enter details of student\n");
                head= insert_front(head);break;

                case 6: printf("first candidate deleted\n");
                head=delete_front(head);break;

                case 7:printf("last candidate deleted\n");
                head=delete_rear(head);break;

                default: exit(0);

           }


      }

  }

  node getnode()
  {
      node new;
    new=(node)malloc(sizeof(struct placed_student));
    //new=1000
    if(new==NULL)
    {
        printf("not created\n");
        exit(0);
    }
    new->next=NULL;
    return new;
  }

  node read_details()
  {
      node temp;
      temp=getnode();
      printf("Enter student name \t branch\t company name\t year\t package\n");
      scanf("%s%s%s%d%d",temp->sname,temp->branch,temp->cname,&temp->year,&temp->package);
  return temp;
  }

  node insert_rear(node head)
  {
      node new, cur;
      new=read_details();
      new->next=NULL;

      if(head==NULL)
      {
          return new;
      }
       cur=head;
       while(cur->next!=NULL)
       {
           cur=cur->next;
       }

       cur->next=new;
       return head;
  }

void display_list(node head)
{
    node cur;
    if(head==NULL)
    {
        printf("List is empty\n");
        return;
    }
    cur=head;
    printf("student name\tbranch \t company name \t year\t package\n");
    while(cur!=NULL)
    {
        printf("%s %s %s %d %d\n",cur->sname,cur->branch,cur->cname,cur->year,cur->package);

        cur=cur->next;
    }

    printf("\n");
}

void display_year(node head)
{
    node cur;
    if(head==NULL)
    {
        printf("List is empty\n");
        return;
    }
    cur=head;
    printf("student name\tbranch \t company name \t year\t package\n");
    while(cur!=NULL)
    {
        if(cur->year==2020)
        printf("%s %s %s %d %d\n",cur->sname,cur->branch,cur->cname,cur->year,cur->package);

        cur=cur->next;
    }

    printf("\n");
}

void display_highestpkg(node head)
{
    node cur, temp;
    int max=INT_MIN;
    if(head==NULL)
    {
        printf("List is empty\n");
        return;
    }
    cur=head;
    printf("student name\tbranch \t company name \t year\t package\n");
    while(cur!=NULL)
    {
        if(cur->next==NULL&&max<cur->package)
        {
            temp=cur;
        }

        else if(max<cur->package)
            temp=cur;
        max=cur->package;
        cur=cur->next;
    }
        printf("%s %s %s %d %d\n",temp->sname,temp->branch,temp->cname,temp->year,temp->package);

    }

  node insert_front(node head)
  {
      node new, cur;
      new=read_details();
      new->next=NULL;

      if(head==NULL)
      {
          return new;
      }
      new->next=head;
      head=new;

       return head;
  }

  node delete_rear(node head)
  {
      node prev,cur;
      if(head==NULL)
      {
          printf("List empty\n");
          return head;
      }

      if(head->next==NULL)
      {
          printf("deleted %s\n",head->sname);
          free(head);
          return NULL;
      }

       prev=NULL;
       cur=head;
       while(cur->next!=NULL)
       {
           prev=cur;
           cur=cur->next;
       }
       printf("deleted %s\n",cur->sname);
       free(cur);
       prev->next=NULL;
       return head;

  }

  node delete_front(node head)
  {
      node cur;
    if(head==NULL)
    {
        printf("List empty\n");
        return head;
    }
    cur=head;
    head=head->next;
    printf("deleted %s\n",cur->sname);
    free(cur);
    return head;
  }

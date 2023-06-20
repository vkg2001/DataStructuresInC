//Almost all SLL

#include<stdio.h>
#include<stdlib.h>

struct employee
{
    char name[20],gender[10];
    int id,age,salary;
    struct employee *next;
};

typedef struct employee *NODE;

NODE getnode()
{
    NODE newn;
    newn=(NODE)malloc(sizeof(struct employee));
    if(newn==NULL)
    {
        printf("NOT CREATED");
        exit(0);
    }
    newn->next=NULL;
    return newn;
}

NODE read_details()
{
    NODE temp;
    temp=getnode();
    printf("ENTER EMP ID, NAME, GENDER, AGE & SALARY:\n");
    scanf("%d %s %s %d %d",&temp->id,temp->name,temp->gender,&temp->age,&temp->salary);
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

NODE insert_front(NODE head)
{
    NODE newn;
    newn=read_details();
    newn->next=NULL;
    if(head==NULL)
        return newn;
    newn->next=head;
    head=newn;
    return head;
}

void display_list(NODE head)
{
    NODE cur=NULL;
    if(head==NULL)
    {
        printf("LIST EMPTY\n");
        exit(0);
    }
    else
    {
        cur=head;
        printf("DETAILS\n");
        printf("EMP ID, NAME, GENDER, AGE & SALARY ARE:\n");
        printf("head-> ");
        while(cur!=NULL)
        {
            printf("%d %s %s %d %d -> ", cur->id, cur->name, cur->gender, cur->age, cur->salary);
            cur=cur->next;
        }
        printf("NULL\n");
    }
}
void count(NODE head)
{
    NODE temp;
    temp=head;
    int count=0;
    if(temp==NULL)
    {
        printf("LIST EMPTY\n");
    }
    else
    {
        while(temp!=NULL)
        {
            if(temp->age>50)
            {
                count++;
            }
            temp=temp->next;
        }
    }
    printf("NO. OF EMPLOYEES ABOVE 50YRS. : %d\n",count);
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

void del_dup(NODE head)
{
    NODE cur=head,index=NULL;
    NODE temp=NULL;
    if(head=NULL)
        return;
    else
    {
        while(cur!=NULL)
        {
            temp=cur;
            index=cur->next;
            while(index!=NULL)
            {
                if(cur->id==index->id)
                    temp->next=index->next;
                else
                    temp=index;
                index=index->next;
            }
            cur=cur->next;
        }
    }
}

NODE pair_swap(NODE head)
{
    NODE prev=head,cur=head->next;
    if(head==NULL||head->next==NULL)
        return NULL;
    head=cur;
    while(1)
    {
        NODE nn=cur->next;
        cur->next=prev;
        if(nn==NULL||nn->next==NULL)
        {
            prev->next=nn;
            break;
        }
        prev->next=nn->next;
        prev=nn;
        cur=prev->next;
    }
    return head;
}

int split_parts(NODE head,NODE second)
{
        NODE temp1,temp2;
        if(head->next==NULL)
                return 0;
        temp1=temp2=head;
        while(temp2->next!=NULL&&temp2->next->next!=NULL)
        {
                temp1=temp1->next;
                temp2=temp2->next->next;
        }
        second=temp1->next;
        temp1->next=NULL;
}

NODE insert_sort(NODE head)
{
    NODE newn,cur,prev;
    newn=read_details();
    if(newn==NULL)
    {
        printf("NOT CREATED\n");
        return NULL;
    }
    else if(head==NULL)
    {
        return newn;
    }
    if(head->age<newn->age)
    {
        newn->next=head;
        return newn;
    }
    cur=head->next;
    prev=head;
    while(cur!=NULL)
    {
        if(head->age<newn->age)
        {
            newn->next=cur;
            prev->next=newn;
            return head;
        }
        prev=cur;
        cur=cur->next;
    }
    prev->next=newn;
    return head;
}

int count_all(NODE head)
{
    NODE temp;
    temp=head;
    int cnt=0;
    if(temp == NULL)
    {
        printf("LIST EMPTY\n");
    }
    else
    {
        while(temp!=NULL)
        {
            cnt++;
            temp=temp->next;
        }
    }
    return cnt;
}

NODE split(NODE head,NODE second,int count)
{
    int i;
    NODE cur,prev;
    if(head==NULL)
    {
        return head;
    }
    cur=head;
    prev=NULL;
    while(i!=count/2)
    {
        prev=cur;
        cur=cur->next;
        i++;
    }
    prev->next=NULL;
    second=cur;
    return second;
}

NODE merged_list(NODE head,NODE second)
{
    NODE cur;
    cur=head;
    while(cur->next!=NULL)
    {
        cur=cur->next;
    }
    cur->next=second;
    return head;
}

int main()
{
    NODE head=NULL,second=NULL,sechead=NULL;
        int choice,cnt;
        printf("\n\nMENU---1.INSERT NODE IN DESCENDING\t2.DISPLAY\t3.INSERT YOUNGEST\t4.INSERT OLDEST\t5.COUNT EMPLOYESS ABOVE 50YRS\t6.REVERSE LIST\t7.DELETE DUPLICATE EMPLOYEE\t8.PAIR SWAP\t9.SPLIT INTO 2[LOGIC 1]\t10.SPLIT INTO 2[LOGIC 2]\t11.MERGE LIST\t12.ENTER SECOND LIST ITEMS\t13.MERGE BOTH LISTS\t14.DISPLAY LIST 2\t15.EXIT\n");
        while(1)
        {
            printf("ENTER CHOICE:\t");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1: head=insert_sort(head);
                break;
                case 2: display_list(head);
                break;
                case 3: head=insert_front(head);
                break;
                case 4: head=insert_end(head);
                break;
                case 5: count(head);
                break;
                case 6: head=reverse_list(head);
                display_list(head);
                break;
                case 7: del_dup(head);
                display_list(head);
                break;
                case 8: head=pair_swap(head);
                display_list(head);
                break;
                case 9: split_parts(head,second);
                printf("LIST 1:\n");
                display_list(head);
                printf("LIST 2:\n");
                display_list(second);
                break;
                case 10: cnt=count_all(head);
                second=split(head,second,cnt);
                printf("\nLIST 1:");
                display_list(head);
                printf("\nLIST 2:");
                display_list(second);
                break;
                case 11: printf("MERGED LIST:\n");
                head=merged_list(head,second);
                second=NULL;
                display_list(head);
                break;
                case 12: sechead=insert_sort(sechead);
                break;
                case 13: printf("MERGED TWO DIFF. LISTS:\n");
                head=merged_list(head,sechead);
                sechead=NULL;
                display_list(head);
                break;
                case 14: display_list(sechead);
                break;
                case 15: exit(0);
                break;
                default: printf("INVALID CHOICE\n");
            }
        }
        return 0;
}

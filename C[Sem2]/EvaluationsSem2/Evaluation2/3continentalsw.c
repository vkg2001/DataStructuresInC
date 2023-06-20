/*Continental Softwares Pvt. Ltd., conducted an Interview for pre-final year candidates in the month of February 2021.
10 candidates were shortlisted for interview from the School of Computer Science Engineering.
There were 2 rounds in the Interview process, Written test and Technical interview round.
The company eliminated 3 candidates who scored lowest in the written test.
Then, the company eliminated 2 candidates who scored lowest in the Technical interview.
The final list was announced by the Continental Softwares offering 10 lacs package for best 2 candidates.
Apply PSF and Implement using Singly linked list.
*/

#include<stdio.h>
#include<stdlib.h>

struct continental
{
    char name[20],branch[20];
    float cgpa;
    int wt,tt;
    struct continental *link;
};
typedef struct continental *NODE;

NODE create();
NODE insert_sort(NODE );
void display_all(NODE );
NODE delete_written(NODE );
NODE delete_technical(NODE );
void display_top(NODE , int);

int main()
{
    NODE head=NULL;
    int ch,w,i,t,f;
    while(1)
    {
        printf("\n---CONTINENTAL SOFTWARE COMPANY INTERVIEW---\n");
        printf("1:Insert Sorted 2:Display 3:Delete written 4:Delete Technical 5:Display top 2 6:Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: head=insert_sort(head);
                    break;
            case 2: display_all(head);
                    break;
            case 3: printf("How many to eliminate in written test?\n");
                    scanf("%d",&w);
                    for(i=0;i<w;i++)
                        head=delete_written(head);
                    break;
            case 4: printf("How many to eliminate in technical test?\n");
                    scanf("%d",&t);
                    for(i=0;i<t;i++)
                        head=delete_technical(head);
                    break;
            case 5: printf("How many to display selected?\n");
                    scanf("%d",&f);
                    display_top(head,f);
                    break;
            case 6: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}

NODE create()
{
    NODE temp=(NODE)malloc(sizeof(struct continental));
    printf("Enter Candidate details-Name,Branch,CGPA,Written Score,Technical Score\n");
    scanf("%s%s%f%d%d",temp->name,temp->branch,&temp->cgpa,&temp->wt,&temp->tt);
    temp->link=NULL;
    return temp;
}

NODE insert_sort(NODE head)
{
    NODE temp=create();
    NODE cur=head, prev=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else if(head->tt < temp->tt)
    {
            temp->link=head;
            head=temp;
    }
    else
    {
        cur=head;
        prev=NULL;
        while(cur->tt > temp->tt && cur->link !=NULL)
         {
            prev=cur;
            cur=cur->link;
        }
        if(cur->link==NULL && cur->tt > temp->tt)
        {
            cur->link=temp;
        }
        else
        {
            prev->link=temp;
            temp->link=cur;
        }
    }
    return head;
}

void display_all(NODE head)
{
    NODE cur=head;
    if(head==NULL)
    {
        printf("List empty\n");
    }
    else
    {
        printf("\nCandidate Details\n");
        while(cur!=NULL)
        {
            printf("%s\t%s\t%0.1f\t%d\t%d\n",cur->name,cur->branch,cur->cgpa,cur->wt,cur->tt);
            cur=cur->link;
        }
    }
}

NODE delete_written(NODE head)
{
    NODE cur=head,prev=NULL, low, lprev;
    int lowwt=1000;
    if(head==NULL)
    {
        printf("List Empty\n");
    }
    else
    {
        while(cur!=NULL)
        {
            if(cur->wt < lowwt)
            {
                lowwt=cur->wt;
                low=cur;
                lprev=prev;
            }
            prev=cur;
            cur=cur->link;
        }
        if(head==low)
        {
            printf("Deleted %s %d\n",low->name,low->wt);
            head=head->link;
            free(low);
        }
        else
        {
            printf("Deleted %s %d\n",low->name,low->wt);
            lprev->link=low->link;
            free(low);
        }
    }
    return head;
}

NODE delete_technical(NODE head)
{
   NODE prev, cur;
   if(head==NULL)
        printf("List is empty\n");
    else
    {
        cur=head;
        while(cur->link != NULL)
        {
            prev=cur;
            cur=cur->link;
        }
        printf("Deleted %s %d\n",cur->name,cur->tt);
        prev->link=NULL;
        free(cur);
    }
    return head;
}


void display_top(NODE head, int f)
{
    NODE cur=head;
    int i;
    if(head==NULL)
        printf("List empty\n");
    else
    {
        for(i=0;i<f;i++)
        {
            printf("%s %d\n",cur->name, cur->tt);
            cur=cur->link;
        }
    }
}

//WYNK
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct wynk
{
    char name[20],singer[20];
    int year;
    float duration;
    struct wynk *next;
};

typedef struct wynk *NODE;

NODE getnode();
NODE insert_end(NODE head);
void display(NODE head);
void display_singer(NODE head,char dsinger[]);;
NODE delete_song(NODE head,char sname[]);
void maxdur(NODE head);
void year(NODE head,int syear);

int main()
{
    int n,syear;
    char dsinger[20],sname[20];
    NODE head=NULL;
    printf("Enter number of songs\n");
    scanf("%d",&n);
    printf("Enter song name, singer name, duration & year\n");
    for(int i=0;i<n;i++)
    {
        head=insert_end(head);
    }
    printf("Enter singer name to search and display\n");
    scanf("%s",dsinger);
    printf("Enter song name to delete\n");
    scanf("%s",sname);
    printf("Enter year of which details to be searched:\n");
    scanf("%d",&syear);
    display(head);
    display_singer(head,dsinger);
    head=delete_song(head,sname);
    display(head);
    maxdur(head);
    year(head,syear);
    return 0;
}

NODE getnode()
{
    NODE newn=(NODE)malloc(sizeof(struct wynk));
    if(newn==NULL)
    {
        printf("Memory not allocated\n");
        exit(0);
    }
    scanf("%s%s%f%d",newn->name,newn->singer,&newn->duration,&newn->year);
    newn->next=newn;
    return newn;
}

NODE insert_end(NODE head)
{
	NODE newn,cur=head;
	newn=getnode( );
	if(head==NULL)
      	{
        return newn; //head=newn;
    	}
	else
    	{
            while(cur->next!=head)
                cur=cur->next;
            cur->next=newn;
            newn->next=head;
       	}
	return head;
}

void display(NODE head)
{
    NODE cur=head;
    if(head==NULL)
    {
        printf("Songs list is empty");
    }
    else
    {
        printf("\nSong name, singer, duration & year\n");
        do
        {
            printf("%s %s %0.2f %d\n",cur->name,cur->singer,cur->duration,cur->year);
            cur=cur->next;
        }while(cur!=head);
    }
}

void display_singer(NODE head,char dsinger[])
{
    NODE cur=head;
    int flag=0;
    if(head==NULL)
    {
        printf("Songs list is empty");
    }
    else
    {
        printf("\nSongs of %s singer\nSong name, singer, duration & year\n",dsinger);
        do
        {
            if(strcmp(cur->singer,dsinger)==0)
            {
                flag=1;
                printf("%s %s %0.2f %d\n",cur->name,cur->singer,cur->duration,cur->year);
            }
            cur=cur->next;
        }while(cur!=head);
        if(flag==0)
            printf("No songs found");
    }
}

NODE delete_song(NODE head,char sname[])
{
    NODE cur=head,prev=NULL;
    if(head==NULL)
    {
        printf("Songs list is empty");
    }
    else if(head->next==head)
    {
        if(strcmp(head->name,sname)==0)
        {
            printf("\nDeleted %s %s %0.2f %d",head->name,head->singer,head->duration,head->year);
            free(head);
            head=NULL;
        }
    }
    else if(strcmp(head->name,sname)==0)
    {
        while(cur->next!=head)
        cur=cur->next;
    prev=head;
    cur->next=head->next;
    head=head->next;
    printf("\nDeleted %s %s %0.2f %d",prev->name,prev->singer,prev->duration,prev->year);
    free(prev);
    }
    else
    {
        do
        {
            if(strcmp(cur->name,sname)==0)
            {
                prev->next=cur->next;
                printf("\nDeleted %s %s %0.2f %d",head->name,head->singer,head->duration,head->year);
                free(cur);
                break;
            }
            prev=cur;
            cur=cur->next;
        }while(cur!=head);
    }
    return head;
}

void maxdur(NODE head)
{
    NODE cur=head,temp;
    float max=head->duration;
    if(head == NULL) {
        printf("Songs list is empty");
    }
    else
        {
         do
         {
             if(max < cur->duration)
                {
                    max=cur->duration;
                    temp=cur;
                }
             cur= cur->next;
        }while(cur != head);

        printf("\nMaximum duration of song in the list: %0.2f", max);
        printf("\n%s %s %0.2f %d\n",temp->name,temp->singer,temp->duration,temp->year);
    }
}

void year(NODE head,int syear)
{
    int flag=0;
    NODE cur=head;
    if(head==NULL)
    {
        printf("Song list is empty\n");
    }
    else
    {
        printf("\nSong(s) of %d year are\n",syear);
        do
        {
            if(cur->year==syear)
            {
                flag=1;
                printf("%s %s %0.2f %d\n",cur->name,cur->singer,cur->duration,cur->year);
            }
            cur=cur->next;
        }while(cur!=head);
            if(flag==0)
            {
                printf("\nSong of %s year not found\n",syear);
            }
    }
}

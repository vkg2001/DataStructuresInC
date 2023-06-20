#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct playlist
{
    struct playlist *prev;
    char name[25],movie[25],singer[25];
    float size;
    struct playlist *next;
};

typedef struct playlist *NODE;

//function prototypes
NODE getnode();
NODE insert_end_dll(NODE head);
NODE insert_after_dll(NODE head,char sname[]);
void display_playlist(NODE head);
NODE delete_song_dll(NODE head, char dname[]);

int main()
{
    int n;
    NODE head=NULL;
    char sname[25],dname[25];
    printf("Enter number of songs:\t");
    scanf("%d",&n);
    if(n>3)
    {
        for(int i=0;i<n;i++)
        head=insert_end_dll(head);
        printf("Songs list:\n");
        display_playlist(head);
        printf("Enter the song name present in playlist after which to add the song:\t");
        scanf("%s",sname);
        printf("Songs list after adding song:\n");
        head=insert_after_dll(head,sname);
        display_playlist(head);
        printf("Enter the song name present in playlist which has to be deleted:\t");
        scanf("%s",dname);
        head=delete_song_dll(head,dname);
        printf("Playlist after deletion\n");
        display_playlist(head);
    }
    else
    {
        printf("Cannot create playlist\n");
    }
    return 0;
}

NODE getnode()
{
    NODE temp;
    temp=(NODE)malloc(sizeof(struct playlist));
    if(temp==NULL)
    {
        printf("Memory not allocated\n");
        exit(0);
    }
    else
    {
        printf("Enter song details: name, singer, size(in mb) & movie name\n");
        scanf("%s %s %f %s",temp->name,temp->singer,&temp->size,temp->movie);
        temp->next=temp->prev=NULL;
    }
    return temp;
}

NODE insert_end_dll(NODE head)
{
    NODE cur=head;
    NODE temp=getnode();
    if(head==NULL)
        head=temp;
    else
    {
        while(cur->next!=NULL)
            cur=cur->next;
        cur->next=temp;
        temp->prev=cur;
    }
    return head;
}

NODE insert_after_dll(NODE head,char sname[25])
{
    NODE temp=getnode();
    NODE cur=head, back=NULL;
    if(head==NULL)
        printf("Adding song not possible. List is empty\n");
    else
    {
        while(cur->next!=NULL)
        {
            if(strcmp(cur->name,sname)==0)
                break;
            back=cur;
            cur=cur->next;
        }
        //one time shift
        back=cur;
        cur=cur->next;
        if(cur==NULL&&strcmp(cur->name,sname)==0)
        {
            back->next=temp;
            temp->prev=back;
        }
        else if(cur!=NULL)
        {
            back->next=temp;
            temp->prev=back;
            temp->next=cur;
            cur->prev=temp;
        }
        else
            printf("Song not present in the playlist\n");
    }
    return head;
}

NODE delete_song_dll(NODE head, char dname[25])
{
    NODE cur=head,back=NULL,fwd=NULL;
    if(head==NULL)
        printf("Playlist is empty\n");
    if(head->next==NULL)
    {
        if(strcmp(head->name,dname)==0)
        {
            printf("Deleted song %s\n",head->name);
            free(head);
            head=NULL;
        }
    }
    if(head->next!=NULL)
    {
        if(strcmp(head->name,dname)==0)
        {
            printf("Deleted song %s\n",head->name);
            cur=head;
            head=head->next;
            head->prev=NULL;
            free(head);
        }
    }
    while(cur->next!=NULL)
    {
        if(strcmp(head->name,dname)==0)
            break;
        back=cur;
        cur=cur->next;
    }
    if(cur->next==NULL)
    {
        if(strcmp(head->name,dname)==0)
        {
            back->next=NULL;
            printf("Deleted sing %s\n",head->name);
            free(cur);
        }
    }
    else if(cur->next!=NULL)
    {
        back->next=cur->next;
        fwd=cur->next;
        fwd->prev=back;
    }
    else("No song present to delete\n");
    return head;
}

void display_playlist(NODE head)
{
    NODE cur=head;
    if(head==NULL)
        printf("Playlist is empty\n");
    else
    {
        printf("Songs in playlist are\n");
        while(cur!=NULL)
        {
            printf("%s %s %s %0.2f",cur->name,cur->singer,cur->movie,cur->size);
            cur=cur->next;
        }
    }
}

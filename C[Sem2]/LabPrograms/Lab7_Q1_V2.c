#include<stdio.h>
#include<stdlib.h>
#include<string.h>



struct playlist
{
char songname[25], singer[25], movie[25];
float size;
struct playlist *next, *prev;
};
typedef struct playlist *NODE;



//function prototypes.
NODE getnewnode();
NODE insert_end_dll(NODE head);
NODE insert_after_dll(NODE head, char sname[25]);
NODE delete_song_dll(NODE head, char dsong[25]);
NODE insert_before(NODE head,char bsong[25]);
void search_song(NODE head,char ssong[25]);
void display_playlist(NODE head);

int main()
{
    int i, n;
    NODE head=NULL;
    char sname[25], dsong[25],bsong[25],ssong[25];
    printf("Enter number of songs\n");
    scanf("%d",&n);
    if(n>3)
    {
        for(i=0;i<n;i++)
        head = insert_end_dll(head);
        display_playlist(head);
        printf("Enter a song present in playlist after which to add the new song\n");
        scanf("%s",sname);
        head = insert_after_dll(head, sname);
        printf("Playlist after inserting\n");
        display_playlist(head);
        printf("Enter a song name to delete\n");
        scanf("%s",dsong);
        head = delete_song_dll(head, dsong);
        printf("Playlist after deleting\n");
        display_playlist(head);
        printf("Enter a song present in playlist before which to add the new song\n");
        scanf("%s",bsong);
        head = insert_before(head, bsong);
        display_playlist(head);
        printf("Enter song which needs to be played\n");
        scanf("%s",ssong);
        search_song(head,ssong);
    }
    else
    {
        printf("Meera cannot create playlist.\n");
    }
    return 0;
}



NODE getnewnode()
{
    NODE newn = (NODE)malloc(sizeof(struct playlist));
    if(newn == NULL)
    {
        printf("Memory not allocated\n");
        exit(0);
    }
    else
    {
        //printf("Enter song detials: song name, singer, size in mb, movie name\n");
        scanf("%s%s%f%s", newn->songname, newn->singer, &newn->size, newn->movie);
        newn->next = newn->prev = NULL;
    }
    return newn;
}



NODE insert_end_dll(NODE head)
{
    NODE cur=head;
    NODE newn = getnewnode();
    if(head==NULL)
        head=newn;
    else
    {
        while(cur->next != NULL)
        cur = cur ->next;
        cur->next = newn;
        newn->prev = cur;
    }
    return head;
}



NODE insert_after_dll(NODE head, char sname[25])
{
    NODE newn = getnewnode();
    NODE cur = head, back = NULL;
    if(head==NULL)
    printf("Adding song is not possible. list is empty\n");
    else
    {
    while(cur -> next != NULL)
    {
        if(strcmp(cur->songname, sname)==0)
        break;
        back = cur;
        cur = cur->next;
    }
    //one time shift.
        back = cur;
        cur = cur->next;
    if(cur == NULL && strcmp(back->songname, sname)==0)
    {
        back->next = newn;
        newn->prev = back;
    }
    else if(cur != NULL)
    {
        back->next = newn;
        newn->prev = back;
        newn->next = cur;
        cur->prev = newn;
    }
    else
        printf("Song not present in the playlist\n");
    }
    return head;
}

NODE delete_song_dll(NODE head, char dsong[25])
{
    NODE cur=head, back = NULL, fwd=NULL;
    if(head==NULL)
        printf("Playlist is empty\n");
    if(head->next == NULL)
    {
        if(strcmp(head->songname, dsong)==0)
        {
            //printf("Deleted song %s\n", head->songname);
            free(head);
            head=NULL;
        }
    }
    if(head->next != NULL)
    {
        if(strcmp(head->songname, dsong)==0)
        {
            //printf("Deleted song %s\n", head->songname);
            cur=head;
            head = head->next;
            head->prev = NULL;
            free(cur);
        }
    }
    while(cur->next != NULL)
    {
        if(strcmp(cur->songname, dsong)==0)
        break;
        back = cur;
        cur = cur->next;
    }
    if(cur->next == NULL)
    {
        if(strcmp(cur->songname, dsong)==0)
            {
            back->next = NULL;
            //printf("Deleted song %s\n", cur->songname);
            free(cur);
            }
    }
    else if( cur ->next != NULL)
    {
        back ->next = cur -> next;
        fwd = cur->next;
        fwd->prev = back;
    }
    else
    printf("No song present to delete\n");
    return head;
}



void display_playlist(NODE head)
{
    NODE cur=head;
    if(head==NULL)
        printf("Playlist is empty\n");
    else
        {
            //printf("Songs in playlist are\n");
            while (cur != NULL)
            {
                printf("%s %s %s %0.2f\n", cur->songname, cur->singer, cur->movie, cur->size);
                cur = cur->next;
            }
        }
}

NODE insert_before(NODE head,char bsong[25])
{
    NODE newn=getnewnode();
    NODE cur=head, back=NULL;
    if(head==NULL)
    {
        head=newn;
    }
    else if(strcmp(cur->songname, bsong)==0)
    {
        newn->next=head;
        head->prev=newn;
        head=newn;
    }
    else
    {
        while(cur->next!=NULL)
        {
            if(strcmp(cur->songname, bsong)==0)
                break;
            back=cur;
            cur=cur->next;
        }
        if(cur->next==NULL&&strcmp(cur->songname, bsong)!=0)
            printf("Song not present\n");
        else
        {
            back->next=newn;
            newn->prev=back;
            newn->next=cur;
            cur->prev=newn;
        }
    }
    return head;
}

void search_song(NODE head,char ssong[25])
{
    NODE cur=head;
    if(head=NULL)
        printf("Song list empty");
    else
    {
        while(cur!=NULL)
        {
            if(strcmp(cur->songname, ssong)==0)
            {
                printf("%s %s %s %0.2f\n", cur->songname, cur->singer, cur->movie, cur->size);
                break;
            }
            cur=cur->next;
        }
        if(strcmp(cur->songname, ssong)!=0)
            printf("Song not found to be played\n");
    }
}

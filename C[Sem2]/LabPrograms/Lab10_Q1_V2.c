#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct toll
{
    char type[5];
    char name[10];
    int num;
    struct toll *next;
};
struct toll *front=NULL;
struct toll *rear=NULL;
void insert(char[],char[],int);
void delete();
void display();
void display_HMV();
void count_LMV();

void main()
{
    int ch,num;
    char Name[10];
    char Type[5];
    while(1)
    {
        printf("PRESS 1.To join the queue 2.To pay toll & leave 3.To display vehicle details 4.Exit\n");
        printf("5.To display HMV vehicles 6.To count no of LMVs\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter vehicle name\n");
                   scanf("%s",Name);
                   printf("Enter type of vehicle\n");
                   scanf("%s",Type);
                   printf("Enter vehicle number\n");
                   scanf("%d",&num);
                   insert(Name,Type,num);
                   break;
            case 2:delete();
                   break;
            case 3:display();
                   break;
            case 5:display_HMV();
                   break;
            case 6:count_LMV();
                   break;
            case 4:exit(0);
                   break;
        }
    }
}
void insert(char name[10],char type[5],int num)
{
    struct toll *newn;
    newn=(struct toll *)malloc(sizeof(struct toll));
    strcpy(newn->name,name);
    strcpy(newn->type,type);
    newn->num=num;
    newn->next=NULL;
    if(front==NULL)
    {
        front=rear=newn;
    }
    else
    {
        rear->next=newn;
        rear=newn;
    }
}
void delete()
{
    if(front==NULL)
    {
        printf("No vehicles\n");
    }
    else
    {
        struct toll *temp=front;
        front=front->next;
        if(strcmp(temp->type,"LMV")==0)
        {
            printf("%s Number:%d Type:%s Amount:Rs 50\n",temp->name,temp->num,temp->type);
        }
        else
        {
            printf("%s Number:%d Type:%s Amount:Rs 100\n",temp->name,temp->num,temp->type);
        }
        free(temp);
    }
}
void display()
{
    if(front==NULL)
    {
        printf("No vehicles\n");
    }
    else
    {
    struct toll *cur=front;
    while(cur->next!=NULL)
    {
        printf("Name:%s Number:%d Type:%s\n",cur->name,cur->num,cur->type);
        cur=cur->next;
    }
    printf("Name:%s Number:%d Type:%s\n",cur->name,cur->num,cur->type);
    }
}
void display_HMV()
{
    int flag=0;
    if(front==NULL)
    {
        printf("No vehicles\n");
    }
    else
    {
    struct toll *cur=front;
    while(cur->next!=NULL)
    {
        if(strcmp(cur->type,"HMV")==0)
        {
            printf("Name:%s Number:%d Type:%s\n",cur->name,cur->num,cur->type);
            flag=1;
        }
        cur=cur->next;
    }
    if(strcmp(cur->type,"HMV")==0)
    {
        printf("Name:%s Number:%d Type:%s\n",cur->name,cur->num,cur->type);
            flag=1;
    }
    if(flag==0)
    {
        printf("No HMV vehicles\n");
    }
    }
}
void count_LMV()
{
    int count=0;
    if(front==NULL)
    {
        printf("No vehicles\n");
    }
    else
    {
    struct toll *cur=front;
    while(cur->next!=NULL)
    {
        if(strcmp(cur->type,"LMV")==0)
        {
            count++;
        }
        cur=cur->next;
    }
    if(strcmp(cur->type,"LMV")==0)
    {
        count++;
    }
    printf("there are %d LMVs in the toll plaza\n",count);
    }
}


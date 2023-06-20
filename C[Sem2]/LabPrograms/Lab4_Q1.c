#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct TV
{
	int year,amt,budget;
	char name[20],lang[20];
	struct TV *link;
};
typedef struct TV *NODE;

NODE create()
{
    NODE k;
    k=(NODE)malloc(sizeof(struct TV));
    if(k==NULL)
    {
        printf("NODE NOT CREATED");
        exit(0);
    }
    k->link=NULL;
    return k;
}
NODE read()
{
    NODE temp;
    temp=create();
    printf("ENTER NAME, LANGUAGE, YEAR, BUDGET, COLLECTION:\n");
    scanf("%s %s %d %d %d",temp->name,temp->lang,&temp->year,&temp->budget,&temp->amt);
    return temp;
}

NODE insert_sort(NODE head)
{
    NODE temp=read();
    NODE cur=head, prev=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else if(head->amt<temp->amt)
    {
            temp->link=head;
            head=temp;
    }
    else
    {
        cur=head;
        prev=NULL;
        while(cur->amt>temp->amt&&cur->link!=NULL)
         {
            prev=cur;
            cur=cur->link;
        }
        if(cur->link==NULL&&cur->amt>temp->amt)
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

void display(NODE head)
{
    NODE cur=head;
    if(head==NULL)
    {
        printf("LIST EMPTY\n");
    }
    else
    {
        printf("\nDETAILS\n");
        while(cur!=NULL)
        {
            printf("%s\t%s\t%d\t%d\t%d\n",cur->name,cur->lang,cur->year,cur->budget,cur->amt);
            cur=cur->link;
        }
    }
}
NODE display_high(NODE head)
{
    NODE cur=head;
    if(head==NULL)
    {
        printf("LIST IS EMPTY\n");
    }
    else
    {
        printf("DETAILS OF HIGHEST:\n");
        printf("%s\t%s\t%d\t%d\t%d\n",head->name,head->lang,head->year,head->budget,head->amt);
    }
    return head;
}
int main()
{
    NODE m=NULL,w=NULL;
	int choice;
	while(1)
	{
		printf("1.INSERT FOR MOVIES\n2.INSERT FOR WEBSERIES\n3.DISPLAY MOVIES\n4.DISPLAY WEBSERIES\n5.DISPLAY HIGHEST\n6.EXIT\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: printf("INSERT MOVIE\n");
                        m=insert_sort(m);
                    break;
			case 2: printf("INSERT WEB-SERIES\n");
                        w=insert_sort(w);
                    break;
            case 3: printf("DISPLAY LIST OF MOVIES\n");
			        display(m);
			        break;
            case 4: printf("DISPLAY LIST OF WEBSERIES\n");
			        display(w);
			        break;
            case 5: printf("\nHIGHEST\n");
                    printf("HIGEST OF MOVIES:\n");
			        display_high(m);
			        printf("\nHIGEST OF WEB-SERIES:\n");
			        display_high(w);
			        break;
            case 6: exit(0);
            default: printf("INVALID CHOICE!\n");
        }
    }
    return 0;
}

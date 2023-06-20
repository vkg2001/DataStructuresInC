#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct products
{
    char pname[20];
    int pnum;
    int doe;
    struct products *next;
} * node;

node getnode()
{
    node ptr = (node)malloc(sizeof(struct products));
    if (ptr == NULL)
    {
        printf("Node not created\n");
        exit(0);
    }
    ptr->next = NULL;
    return ptr;
}

node read_details()
{
    node details;
    details = getnode();
    printf("Enter Products details:\nProduct Name\tProduct Number\tDate of expiry:\n");
    scanf("%s %d %d", details->pname, &details->pnum, &details->doe);
    return details;
}

//insertion
node insert_front(node head)
{
    node ptr;
    ptr = read_details();
    if (head == NULL)
    {
        return ptr; //if list is empty return the pointer only to main
    }
    ptr->next = head;
    head = ptr;
    return head;
}

node insert_end(node head)
{
    node ptr = NULL, p = NULL;
    ptr = read_details();
    if (head == NULL)
    {
        printf("List was empty!!\n");
        return ptr; //if list is empty return the pointer only to main
    }
    else
    {
        p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = ptr;
    }
    return head;
}

node insert_specific(node head)
{
    node ptr = read_details();
    if (head==NULL)
    {
        printf("List was empty\n");
        return ptr;
    }

    node p = head;
    int i = 0, index;
    printf("Enter index:\n");
    scanf("%d", &index);

    while (i < index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

node insert_after(node head)
{
    node ptr = read_details();
    printf("Enter product name after which u want to add\n");
    char buf[20];
    scanf("%s", buf);

    if (head == NULL)
    {
        printf("List is empty!!\n");
        return ptr;
    }
    node p = head;
    node q = head->next;
    while (strcmp(buf, p->pname) != 0)
    {
        p = p->next;
        q = q->next;
    }
    p->next = ptr;
    ptr->next = q;
    return head;
}

//Above all insertion

void display_list(node head)
{
    node cur=NULL;
    if(head==NULL)
    {
        printf("List Empty\n");
        exit(0);
    }
    else
    {
        cur=head;
        printf("DETAILS\n");
        printf("Product Name, Number & DOE are:\n");
        printf("head-> ");
        while(cur!=NULL)
        {
            printf("%s %d %d -> ", cur->pname, cur->pnum, cur->doe);
            cur=cur->next;
        }
        printf("NULL\n");
    }
}

int main()
{
    node head = NULL;
    int ch;
    while (1)
    {
        printf("\n*******\n1.Exit\t2.Insert front\t3.Insert End\t4.Insert at specific\t5.Insert After\t6.Display\n");
        printf("Enter choice: \n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            exit(0);
            break;
        case 2:
            printf("Adding at front \n");
            head = insert_front(head);
            break;

        case 3:
            printf("Adding at end\n");
            head = insert_end(head);
            break;
        case 4:
            printf("Adding at Specific\n");
            head = insert_specific(head);
            break;
        case 5:
            printf("Adding after\n");
            head = insert_after(head);
            break;
        case 6:
            printf("Display list\n");
            display_list(head);
            break;
        default:
            printf("\n*********\n");
            break;
        }
    }
    return 0;
}

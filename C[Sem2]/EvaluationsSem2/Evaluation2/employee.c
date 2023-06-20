//Almost all SLL

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct employee
{
    char name[20];
    int id;
    int age;
    char gender;
    int salary;
    struct employee *next;
} NODE;
NODE *getnode();
NODE *printsll(NODE *);
NODE *readsll(NODE *, int *);
NODE *desecding_order(NODE *);
NODE *insertFront(NODE *);
NODE *insertEnd(NODE *);
NODE *split(NODE *, int);
NODE *split_alternative(NODE *);
NODE *male(NODE *);
NODE *merge(NODE *);
NODE *above50(NODE *);
NODE *repeat(NODE *);
NODE *swap_alternative(NODE *);
int main()
{

    NODE *head = getnode();
    choose(head);

    return 0;
}
void choose(head)
{
    int num, n;

    while (1)
    {
        printf("1-> read\n2->print\n3->sort descending\n4-> insert front\n5-> insert end\n6-> split\n7-> split alternative\n8->Male emloyee\n9->merge\n10->above 50\n11->delete repeat\n12-> swap alternative\n");
        scanf("%d", &num);

        switch (num)
        {
        case 0:
            exit(0);
            break;
        case 1:
            head = readsll(head, &n);
            break;
        case 2:
            head = printsll(head);
            break;
        case 3:
            head = desecding_order(head);
            break;
        case 4:
            head = insertFront(head);
            break;
        case 5:
            head = insertEnd(head);
            break;
        case 6:
            head = split(head, n);
            break;
        case 7:
            head = split_alternative(head);
            break;
        case 8:
            head = male(head);
            break;
        case 9:
            head = merge(head);
            break;
        case 10:
            head = above50(head);
            break;
        case 11:
            head = repeat(head);
            break;
        case 12:
            head=swap_alternative(head);
            break;

        default:
            printf("Invalid input");
            break;
        }
    }
}
NODE *getnode()
{
    NODE *newnode;
    newnode = (NODE *)malloc(sizeof(NODE));

    return newnode;
}
NODE *readsll(NODE *head, int *n)
{
    NODE *prev, *curr;
    printf("Enter no. of employees\n");
    scanf("%d", n);

    curr = head;
    prev = head;

    for (int i = 0; i < *n; i++)
    {
        printf("Enter age id salary gender and name:\n");

        scanf("%d %d %d %c %s", &curr->age, &curr->id, &curr->salary, &curr->gender, curr->name);
        prev->next = curr;
        curr->next = NULL;
        prev = curr;
        curr = getnode();
    }

    return head;
}
NODE *printsll(NODE *head)
{

    NODE *ptr = head;
    while (ptr != NULL)
    {
        printf("%d\t%d\t%d\t%c\t%s\n", ptr->id, ptr->age, ptr->salary, ptr->gender, ptr->name);
        ptr = ptr->next;
    }

    return head;
}
NODE *desecding_order(NODE *head)
{
    NODE *curr, *ptr;
    int age, id, salary;
    char gender;
    char name[20];

    if (head == NULL)
    {
        printf("desending_order failed");
        return head;
    }
    else
    {
        curr = head;

        while (curr != NULL)
        {
            ptr = curr->next;
            while (ptr != NULL)
            {
                if (curr->age < ptr->age)
                {
                    age = curr->age;
                    id = curr->id;
                    salary = curr->salary;
                    gender = curr->gender;
                    strcpy(name, curr->name);

                    curr->age = ptr->age;
                    curr->id = ptr->id;
                    curr->salary = ptr->salary;
                    curr->gender = ptr->gender;
                    strcpy(curr->name, ptr->name);

                    ptr->age = age;
                    ptr->id = id;
                    ptr->salary = salary;
                    ptr->gender = gender;
                    strcpy(ptr->name, name);
                }
                ptr = ptr->next;
            }

            curr = curr->next;
        }
    }

    printf("Sort successful");

    return head;
}
NODE *insertFront(NODE *head)
{

    if (head == NULL)
    {
        printf("Head NULL in inserFront");
        return head;
    }
    else
    {
        NODE *curr;
        curr = getnode();

        if (curr == NULL)
        {
            printf("Get node failed in inserFront");
            return head;
        }
        else
        {
            printf("Enter age id salary gender and name:\n");
            scanf("%d %d %d %c %s", &curr->age, &curr->id, &curr->salary, &curr->gender, curr->name);

            curr->next = head;

            return curr;
        }
    }
}
NODE *insertEnd(NODE *head)
{
    if (head == NULL)
    {
        printf("Head NULL in insertend");
        return head;
    }
    else
    {
        NODE *ptr = head, *curr = getnode();

        if (curr == NULL)
        {
            printf("Getnode failed in insertend");
            return head;
        }

        else
        {
            ptr = head;

            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }

            printf("Enter details");
            scanf("%d %d %d %c %s", &curr->age, &curr->id, &curr->salary, &curr->gender, curr->name);
            ptr->next = curr;
            curr->next = NULL;
        }
    }

    return head;
}

NODE *split(NODE *head, int c)
{
    NODE *head1 = head, *head2, *ptr;

    ptr = head;

    for (int i = 0; i < c / 2; i++)
    {
        ptr = ptr->next;
    }

    head2 = ptr->next;
    ptr->next = NULL;

    printf("First sll\n");
    head1 = printsll(head1);
    printf("\nSecond sll\n");
    head2 = printsll(head2);

    return head; // only head1 will be returned
}
NODE *split_alternative(NODE *head)
{
    NODE *curr, *temp, *head1, *head2;

    curr = head;
    head1 = head;
    head2 = curr->next;

    while (curr->next != NULL)
    {
        temp = curr->next;
        curr->next = curr->next->next;
        temp->next = temp->next->next;
        curr = curr->next;
    }

    head1 = printsll(head1);
    printf("\n");
    head2 = printsll(head2);

    return head;
}
NODE *male(NODE *head)
{
    NODE *ptr = head, *headm = getnode(), *ptrm = headm, *curr = headm;
    int age, id, salary;
    char gender;
    char name[20];

    while (ptr != NULL)
    {
        if (ptr->gender == 'M')
        {

            curr->age = ptr->age;
            curr->id = ptr->id;
            curr->salary = ptr->salary;
            curr->gender = ptr->gender;
            strcpy(curr->name, ptr->name);

            curr->next = NULL;

            ptrm->next = curr;
            ptrm = curr;
            curr = getnode();
        }

        ptr = ptr->next;
    }

    headm = printsll(headm);

    return head;
}
NODE *merge(NODE *head)
{

    int n;
    printf("Enter list to be merged\n");

    NODE *head2 = getnode(), *ptr = head;

    head2 = readsll(head2, &n);

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->next = head2;

    printf("\nMerge succesful\n");
}
NODE *above50(NODE *head)
{
    NODE *ptr = head;
    int c = 0;

    while (ptr != NULL)
    {
        if (ptr->age > 50)
        {
            c++;
        }
        ptr = ptr->next;
    }

    printf("\nThe no of employees of age above 50:%d\n", c);

    return head;
}
NODE *repeat(NODE *head)
{
    NODE *ptr = head, *index, *temp,*prev;

    while (ptr != NULL)
    {
        index = ptr->next;
        prev=ptr;

        while (index != NULL)
        {
            if (index->id == ptr->id)
            {
                prev->next=index->next;
                free(index);
            }
            else
            {
                prev=index;
            }
            index = index->next;
        }
        ptr = ptr->next;
    }

    printf("\nDeletion succesful\n");

    return head;
}

NODE *swap_alternative(NODE *head)
 {

     NODE *prev=head,*curr=head->next,*temp;

     head=curr;

     while(prev->next!=NULL)
     {
        temp=curr->next;
        curr->next=prev;
        prev->next=temp;
        prev=temp;
        curr=temp->next;

     }

     return head;
 }

/*Blockchain is the new technology in computer science, where it is used to store the ‘n’ transaction
details of users. Sham is very much interested in implementing blockchain kind of technology
using C programming. Transaction details contains: Transaction_ID, sender name, receiver name,
amount. Please help Sham to implement the above problem and perform the below operations.
i) Display the transaction details of particular Transaction_ID.
ii) Display the transaction details by sender name.
Note: Use Pointer with structure & typedef*/

#include<stdio.h>

typedef struct blockchain_transaction
{
    int tid;//transaction id
    int s_name[100];//sender's name
    int r_name[100];//receiver's name
    float amt;//amount sent/received
}BTXN;

void read(BTXN *b,int n)//to read the structure array
{
    printf("ENTER DETAILS\n\n");
    for(int i=0;i<n;i++)
    {
        printf("Enter transaction id\n");
        scanf("%d",&(b+i)->tid);
        printf("Enter Sender's name\n");
        scanf("%s",(b+i)->s_name);
        printf("Enter Receiver's name\n");
        scanf("%s",(b+i)->r_name);
        printf("Enter Amount\n");
        scanf("%f",&(b+i)->amt);
    }
}

void display(BTXN *b,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("TCXN ID:%d\tSender:%s\tReceiver:%s\tAmount:%f\n",(b+i)->tid,(b+i)->s_name,(b+i)->r_name,(b+i)->amt);
    }
}

void search_detail(BTXN *b,int trans,int n)
{
    int f=0;
    for(int i=0;i<n;i++)
    {
        if((b+i)->tid==trans)
        {
            printf("Search succesful\n");
            printf("TCXN ID:%d\tSender:%s\tReceiver:%s\tAmount:%f\n\n",(b+i)->tid,(b+i)->s_name,(b+i)->r_name,(b+i)->amt);
            f=1;
            break;
        }
    }
    if(f==0)
        printf("No details exist with transaction id:%d\n\n",trans);
}
void main()
{
    int n;
    printf("Enter number of transactions\n");
    scanf("%d",&n);
    BTXN b[n];
    read(b,n);
    int trans;
    printf("\nEnter transaction id to search\n");
    scanf("%d",&trans);
    search_detail(b,trans,n);
    printf("All transaction details are:\n");
    display(b,n);
}

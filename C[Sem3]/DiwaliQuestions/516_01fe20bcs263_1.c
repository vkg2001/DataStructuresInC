#include <stdio.h>
#include <stdlib.h>

struct advertisment
{
    char message_sent[100];
    int time[2];
};
typedef struct advertisment AD;

struct stack
{
    int top;
    int active;
    AD items[6];
}x1,x2;

typedef struct stack STACK;

int change_count=0;

STACK createStack()
{
    STACK st;
    st.top = -1;
    st.active = 0;
    return st;
}

int isEmpty(STACK stack)
{
    if(x1.top==-1)
    {
        x1.active = 0;
        x2.active = 1;
    }
    else
    {
        x1.active = 1;
        x2.active = 0;
    }
    return stack.top == -1;
}

STACK push(STACK stack,AD item)
{
    stack.items[++stack.top] = item;
    return stack;
}

STACK pop(STACK stack)
{
    x2=push(x2,stack.items[stack.top]);
    stack.top--;
    return stack;
}

int main()
{
    int choice;
    x1 = createStack();
    x2 = createStack();
    AD items[6] = {
                    [0].message_sent  = "Have snacks at nearest hotels",
                    [0].time[0]       = 8,
                    [0].time[1]       = 9,
                    [1].message_sent  = "Have cup of coffee to start your day",
                    [1].time[0]       = 9,
                    [1].time[1]       = 10,
                    [2].message_sent  = "Shop for your newborns",
                    [2].time[0]       = 10,
                    [2].time[1]       = 11,
                    [3].message_sent  = "Great discounts, shop for your complete family",
                    [3].time[0]       = 11,
                    [3].time[1]       = 12,
                    [4].message_sent  = "Watch a movie to make your day",
                    [4].time[0]       = 12,
                    [4].time[1]       = 1,
                    [5].message_sent  = "Hungry, try out our exotic lunch menu",
                    [5].time[0]       = 1,
                    [5].time[1]       = 2,
                };
    x1=push(x1,items[5]);
    x1=push(x1,items[4]);
    x1=push(x1,items[3]);
    x1=push(x1,items[2]);
    x1=push(x1,items[1]);
    x1=push(x1,items[0]);
    x1.active = 1;
    while(1)
    {
        if(change_count>=5) isEmpty(x1);
        printf("\nMessage\n");
        printf("1.Message Being Broadcasted\n");
        printf("2.Update Time\n");
        printf("3.Print left over messages\n");
        printf("4.Print all the message\n");
        printf("5.Exit the shop\n\n");
        printf("Enter Your Choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1  : if(x1.active == 1)
                        printf("Current Message: \n%s\n",x1.items[x1.top].message_sent);
                      else
                        printf("Current Message: \n%s\n",x2.items[x2.top].message_sent);
                      break;
            case 2  : if(x1.active == 1)
                      {
                        x1=pop(x1);
                        printf("Updated time\nCurrent Message: \n%s\n",x1.items[x1.top].message_sent);
                      }
                      else
                      {
                        x2=pop(x2);
                        printf("Updated time\nCurrent Message: \n%s\n",x2.items[x2.top].message_sent);
                      }
                      break;
            case 3  : if(x1.active == 1)
                      {
                        printf("Remaining Messages: \n\n");
                        for(int i=x1.top;i>=0;i--)
                          printf("%d. %s\n",x1.top-i+1,x1.items[i].message_sent);
                      }
                      else
                      {
                        printf("Remaining Messages: \n\n");
                        for(int i=x2.top;i>=0;i--)
                          printf("%d. %s\n",x2.top-i+1,x2.items[i].message_sent);
                      }
                      break;
            case 4  : printf("\nRemaining texts in first stack: \n\n");
                      for(int i=x1.top;i>=0;i--)
                        printf("%d. %s\n",x1.top-i+1,x1.items[i].message_sent);
                      printf("\n\nRemaining texts in second stack: \n\n");
                      for(int j=x2.top;j>=0;j--)
                        printf("%d. %s\n",x2.top-j+1,x2.items[j].message_sent);
                      break;
            case 5  : exit(0);
            default : printf("Wrong Choice\n");
                      break;
        }
    }
    return 0;
}

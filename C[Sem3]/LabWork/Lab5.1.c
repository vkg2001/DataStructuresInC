#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct student
{
char name[10];
int id;
int sem;
int cgpa;
struct student *left;
struct student *right;
};
typedef struct student *node;
node insert(node,char[],int,int,int);
int search(node,int);
void display(node,int);
node getnode( char[],int,int ,int );
node dlete(node ,int );
node least(node);
void parentnode(node ,int);
node lr(node ,int );
void frontrear(node);

 node insert(node root, char tname[],int tid,int tsem,int tcgpa)
 {
     if(root==NULL)
     {
         root=getnode(tname,tid,tsem,tcgpa);
     }
     else if(root->id>tid)
     {
         root->left=insert(root->left,tname,tid,tsem,tcgpa);
     }
     else
     {
         root->right=insert(root->right,tname,tid,tsem,tcgpa);
     }
     return root;
 }
 node getnode( char tname[],int tid,int tsem,int tcgpa)
 {
     node temp;
     temp=(node)malloc(sizeof(struct student));
     temp->right=NULL;
     temp->left=NULL;
     strcpy(temp->name,tname);
     temp->id=tid;
     temp->cgpa=tcgpa;
     temp->sem=tsem;
     return temp;

 }
 int search(node root,int key)
 {
     if(root!=NULL)
     {
         if(root->id==key)
         {
             return 1;
         }
         else if(root->id>key)
         {
             search(root->left,key);
         }
         else if(root->id<key)
         {
             search(root->right,key);
         }
     }

     else
        return 0;
 }
 void display(node root,int c)
 {

     if(c==1)
         {
             if(root!=NULL)
             {
                 display(root->left,c);
                 printf("name-%s\nid-%d\nsem-%d\ncgpa-%d\n",root->name,root->id,root->sem,root->cgpa);
                 display(root->right,c);
                 return;
             }
         }
    else if(c==2)
    {
        if(root!=NULL)
             {
                  printf("name-%s\nid-%d\nsem-%d\ncgpa-%d\n",root->name,root->id,root->sem,root->cgpa);
                  display(root->left,c);
                  display(root->right,c);
                 return;
             }
    }
    else
    {
         if(root!=NULL)
             {
                  display(root->left,c);
                  display(root->right,c);
                  printf("name-%s\nid-%d\nsem-%d\ncgpa-%d\n",root->name,root->id,root->sem,root->cgpa);
                 return;
             }
    }
 }
 node dlete(node root,int key)
 {


 if(root!=NULL)
    {
        if(root->id==key)
        {
            if(root->left==NULL&&root->right==NULL)
            {
            free(root);
            root=NULL;
            return root;
            }
              else if(root->left==NULL)
              {
                  node temp;
                  temp=root;
                  root=root->right;
                  free(temp);
                  return root;
              }
              else if(root->right==NULL)
              {
                  node temp;
                  temp=root;
                  root=root->left;
                  free(temp);
                  return root;
              }
              else
              {
                  node temp;
                  temp=least(root->right);
                  root=temp;
                  dlete(root->right,temp->id);
              }
              return root;

        }


        else if(root->id>key>0)
        {
           root->left=dlete(root->left,key);
           return root;
        }
        else if(root->id<key)
       {
          root->right= dlete(root->right,key);
          return root;
       }



 }
 }

 node least(node cur)
 {
     while(cur->left!=NULL)
     {
         cur=cur->left;
     }
     return cur;
 }
void parentnode(node aux,int key)
{
      if(aux!=NULL)
     {
         if(aux->right->id==key||aux->left->id==key)
         {
             printf(" parent id is %d",aux->id);
         }
         else if(aux->id>key)
         {
             parentnode(aux->left,key);
         }
         else if(aux->id<key)
         {
             parentnode(aux->right,key);
         }
     }

     else
        printf("you have entered wrong data");
}
node lr(node root,int key)
{
    if(root!=NULL)
     {
         if(root->id==key)
         {
             if(root->right==NULL&&root->left==NULL)
                printf("its a leaf node");
             else if(root->right==NULL)
             {
                 root=root->left;
                 printf("left sub tree \n name-%s\nid-%d\nsem-%d\ncgpa-%d\n",root->name,root->id,root->sem,root->cgpa);
             }
              else if(root->left==NULL)
              {
                  root=root->right;
                printf("right sub tree name-%s\nid-%d\nsem-%d\ncgpa-%d\n",root->name,root->id,root->sem,root->cgpa);
              }
                else
                {
                    node temp=root;
                    temp=temp->right;
                    root=root->left;
                    printf(" \n left sub tree \n name-%s\nid-%d\nsem-%d\ncgpa-%d\n",root->name,root->id,root->sem,root->cgpa);
                  printf(" \n right sub tree \n name-%s\nid-%d\nsem-%d\ncgpa-%d\n",temp->name,temp->id,temp->sem,temp->cgpa);
                }


         }
         else if(root->id>key)
         {
             lr(root->left,key);
         }
         else if(root->id<key)
         {
             lr(root->right,key);
         }
     }

     else
        printf("key does not exsist");
}
void frontrear(node r1)
{
    if(r1!=NULL)
    {
        r1=r1->left;
        printf(" left view \n %d",r1->id);

    }

}

main()
{
     int tid,tsem,tcgpa,key,s,c;
     int dkey;
    char tname[10];
    node root;
    root=NULL;
    int ch;
    while(1)
    {
      printf("press 1 to insert\n 2 to search\n 3 to display \n 4 to delete\n 5 to exit \n ");
      scanf("%d",&ch);
      switch(ch)
      {
      case 1:
             printf(" enter name,id,sem,cgpa of the student \n");
             scanf("%s%d%d%d",tname,&tid,&tsem,&tcgpa);
             root=insert(root,tname,tid,tsem,tcgpa);
             break;
      case 2:
          printf("enter the id of the student you want to search");
          scanf("%d",&key);
          s=search(root,key);
          if(s==1)
            printf("student id found");
          else
            printf("student id not found");
          break;
      case 3:
           printf("press 1 to print it in order\n 2 to print in pre order \n 3 to print in post order");
          scanf("%d",&c);
          display(root,c);
          break;
      case 4:
          printf("enter the student id you want to delete");
          scanf("%d",&dkey);
          root=dlete(root,key);
          break;
      case 5:
           break;


         if(ch==5)
            break;
    }
    }
}

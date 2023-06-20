#include<stdio.h>
#include<stdlib.h>

typedef struct student
{
    char name[10];
    int ID;
    int sem;
    int CGPA;
    struct student *left,*right;
}*NODE;

NODE create()
{
    NODE newn=(NODE)malloc(sizeof(struct student));
    printf("Enter the Name, ID, Semester & CGPA of student\n");
    scanf("%s %d %d %d",newn->name,&newn->ID,&newn->sem,&newn->CGPA);
    newn->left=newn->right=NULL;
    return newn;
}

NODE insert(NODE root,NODE newn)
{
    if(root==NULL)
        root=create();
    else if(newn->ID>root->ID)
        root->right=insert(root->right,newn->ID);
    else if(newn->ID<root->ID)
        root->left=insert(root->left,newn->ID);
    return root;
}

NODE search(NODE root,int key)
{
    if(root==NULL)
        return 0;
    else if(root->ID==key)
        return 1;
    else if(root->ID < key)
        return search(root->right,key);
    else if (root->ID > key)
        return search(root->left,key);
}

NODE delete(NODE root,int key)
{
    if(root->ID==key)
    {
        NODE temp;
        if(root->right==NULL)
        {
            temp=root->left;
            free(root);
            return temp;
        }
        else if(root->left==NULL)
        {
            temp=root->right;
            free(root);
            return temp;
        }
        else
        {
            int ma=max(root->left);
            root->ID = max;
            temp = delete(root->left,ma);
            free(temp);
        }
    }
    else
    {
        if(key>root->ID)
            root->right=delete(root->right,key);
        else if(key<root->ID)
            root->left=delete(root->left,key);
    }
    return root;
}

void preorder(NODE root)
{
	if(root!=NULL)
	{
		printf("%d ",root->ID);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(NODE root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
        printf("%d ",root->ID);
	}
}

void inorder(NODE root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d ",root->ID);
		inorder(root->right);
	}
}

void find_parent(NODE root,int key,int parent)
{
    if (root == NULL)
        return;
    if (root->ID==key)
            printf("Parent of %d is %d",key,parent);
    else
    {
        find_parent(root->left, key, root->ID);
        find_parent(root->right, key, root->ID);
    }
    printf("Parent node of given ID is %d",parent);
}

void print_level(NODE root, int current_level, int num)
{
    if(root == NULL)
        return;
    if(root->ID == num)
        printf("Level of %d is %d \n", num, current_level);
    print_level(root->left, current_level+1, num);
    print_level(root->right, current_level+1, num);
}

int print_ancestors(NODE root,int num)
{
  if (root == NULL)
     return 0;
  if (root->ID == num)
     return 1;
  if (print_ancestors(root->left, num) || print_ancestors(root->right, num) ) {
      printf("%d ", root->ID);
      return 1;
  } else {
      return 0;
  }
}

int highest_CGPA(NODE root)
{
    if (root->right==NULL)
    {
        printf("Highest CGPA is %d\n", root->CGPA);
        return root->CGPA;
    }
    else
        highest_CGPA(root->right);
}

int largestbinary(NODE root)
{
  if(root == NULL)
    return 0;
   if (largestbinary(root))
     return max(root);
   else
    return max(largestbinary(root->left), largestbinary(root->right));
}

int main()
{
    NODE root=NULL,newn;
    int choice,key,key1,key2,r,parent,current_level=0,num,num1,high,anc,lar;
    while (1)
    {
        printf("\n1.Insert\t2.Search\t3.Delete\t4.Traversals\t5.Parent Node\t6.Level of Node\t7.Anscestors of given Node\t8.Highest CGPA\t9.Largest BST\t10.EXIT\tdefault: Invalid choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            root=insert(root,newn);
            break;
        case 2:
            printf("Enter key to search\n");
            scanf("%d",&key);
            r = search(root, key);
            if (r == 1)
                printf("Key found\n");
            else if (r == 0)
                printf("Key not found\n");
            break;
        case 3:
            printf("Enter key to delete\n");
            scanf("%d",&key1);
            root=delete(root,key1);
            printf("Element deleted\n");
            break;
        case 4:
            printf("\nInorder Traversal: ");
            inorder(root);
            printf("\nPreorder Traversal: ");
            preorder(root);
            printf("\nPostorder Traversal: ");
            postorder(root);
            break;
        case 5:
            printf("Enter the ID of whose parent you want to visit");
            scanf("%d",&key2);
            find_parent(root,key2,parent);
            break;
        case 6:
            printf("Enter the ID of whose level you want to find out");
            scanf("%d",&num1);
            print_level(root,current_level,num1);
            break;
        case 7:
            printf("Enter the ID of whose ancestor you wish to see");
            scanf("%d",&num);
            anc=print_ancestors(root,num);
            break;
        case 8:
            high=highest_CGPA(root);
            break;
        case 9:
            lar=largestbinary(root);
            printf("Largest binary sub tree is %d",lar);
            break;
        case 10:
            printf("End the program\n");
            exit(0);
        default: printf("Invalid choice!\n");
        }
    }
    return 0;
}

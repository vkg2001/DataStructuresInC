#include<stdio.h>
#include<stdlib.h>

typedef struct BST
{
	int data;
	struct BST *left;
	struct BST *right;
}*node;

node create();
void insert(node ,node );
void inorder(node );
int count_node(node );
int count_leaf(node );
int count_parent(node );
int search(int item,node root);
int max(int a,int b);
int c=0,c1=0,c2=0;

int main()
{
	char ch;
	int item,f=0;
	node root=NULL,temp;
	do
	{
		temp=create();
		if(root==NULL)
			root=temp;
		else
			insert(root,temp);

		printf("\nDo you want to enter more(y/n)?");
		getchar();
		scanf("%c",&ch);
	}while(ch=='y'|ch=='Y');
	printf("\nInorder Traversal: ");
	inorder(root);

printf("\nNo of nodes in the tree=%d\n",count_node(root));
printf("\nNo of leaf nodes in the tree=%d\n",count_leaf(root));
printf("\nNo of parent nodes in the tree=%d\n",count_parent(root));
printf("\nEnter item to be searched\n");
    scanf("%d",&item);
    f=search(item,root);
    if(f==1)
        printf("found\n");
    else
        printf("not found\n");
return 0;
}

node create()
{
	node temp;
	printf("Enter data:");
	temp=(node)malloc(sizeof( struct BST));
	scanf("%d",&temp->data);
	temp->left=temp->right=NULL;
	return temp;
}

void insert(node root,node temp)
{
	if(temp->data<root->data)
	{
		if(root->left!=NULL)
			insert(root->left,temp);
		else
			root->left=temp;
	}

	if(temp->data>root->data)
	{
		if(root->right!=NULL)
			insert(root->right,temp);
		else
			root->right=temp;
	}
}

void inorder(node root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}

int count_node(node root)
{
    if(root!=NULL)
	{
        count_node(root->left);
        c++;
        count_node(root->right);
        return c;
    }
}

int count_leaf(node root)
{
    if(root!=NULL)
	{
	    count_leaf(root->left);
	    if(root->left==NULL && root->right==NULL)
            c1++;
        count_leaf(root->right);
	return c1;
	}
}

int count_parent(node root)
{
    if(root!=NULL)
	{
	    count_parent(root->left);
	    if(root->left!=NULL && root->right!=NULL)
            c2++;
        count_parent(root->right);
	return c2;
	}
}

int search(int item,node root)

{
    while(root!=NULL)
    {
        if(item>root->data)
        {
            return search(item,root->right);
        }
        else if(item<root->data)
        {
            return search(item,root->left);
        }
        else
        {
            return 1;
        }
    }
    return 0;
}

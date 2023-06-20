#include<stdio.h>
#include<stdlib.h>

typedef struct BT
{
	int data;
	struct BT *left,*right;
}*node;

node create();
void insert(node ,node );
void inorder(node );

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
		printf("Do you want to enter more(y/n)?");
		getchar();
		scanf("%c",&ch);
	}while(ch=='y'|ch=='Y');
	printf("Inorder Traversal: ");
	inorder(root);
return 0;
}

node create()
{
	node temp;
	printf("Enter data:");
	temp=(node)malloc(sizeof(struct BT));
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

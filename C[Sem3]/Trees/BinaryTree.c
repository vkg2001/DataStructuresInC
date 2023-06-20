#include<stdio.h>
#include<stdlib.h>

typedef struct BT
{
    int data;
    struct BT *left,*right;
}*NODE;

NODE create(int data)
{
	NODE temp=(NODE)malloc(sizeof(struct BT));
	temp->data=data;
	temp->left=temp->right=NULL;
	return temp;
}

NODE insert(NODE node,int data)
{
    if(node==NULL){
        node=create(data);
        return node;
    } else if(data<node->data){
        node->left=insert(node->left,data);
    } else if(data>node->data){
        node->right=insert(node->right,data);
    }
    return node;
}

NODE inorder(NODE node){
    if(node!=NULL){
        inorder(node->left);
        printf("%d ",node->data);
        inorder(node->right);
    }
    return node;
}

int main()
{
    NODE root;
    int ch,data;
    while(1)
    {
        printf("Enter the choice:");
        printf("1. Insert\t2. Display\t3.EXIT\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: scanf("%d",&data);
                root=insert(root,data);
                break;
            case 2: printf("Inorder Traversal: ");
                inorder(root);
            default: exit(0);
        }
    }
    return 0;
}

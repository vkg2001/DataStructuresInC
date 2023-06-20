#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

 struct treenode
{
    int data;
    struct node *left;
    struct node *right;
};

struct treenode *createnode(int data)
{
    struct treenode *newnode = malloc(sizeof(struct treenode));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct treenode *insertion(struct treenode *node, int data)
{
    if (node == NULL)
    {
        node = createnode(data);
        return node;
    }
    else if (data < (node)->data)
    {
        node->left = insertion(node->left, data);
    }
    else if (data > (node)->data)
    {
        node->right = insertion(node->right, data);
    }
    return node;
}

struct treenode *traverse(struct treenode *node)
{
    if (node != NULL)
    {
        traverse(node->left);
        printf("%3d\n", node->data);
        traverse(node->right);
    }
    return node;
}

int countnodes(struct treenode *node)
{
    if(node==NULL)
    {
        printf("tree is empty\n");
        return 0;
    }
    else
        return 1+ countnodes(node->left)+countnodes(node->right);
}

int countleafnodes(struct treenode *node)
{
    int child = 0;
    if (node == NULL)
    {
        return 0;
    }
    else if (node->left == NULL && node->right == NULL)
    {
        child++;
    }
    else
    {
        return countleafnodes(node->left) + countleafnodes(node->right);
    }
    return child;
}

int countparentnodes(struct treenode *node)
{
    if(node==NULL)
        return 0;
    else if (node->left!=NULL||node->right!=NULL)
    {
        return 1+countparentnodes(node->left)+countparentnodes(node->right);
    }
    else
        return 0;

}

int maxvalue(struct treenode*node)
{
    if(node==NULL)
        return 0;
    int max=node->data;
    int left=maxvalue(node->left);
    int right=maxvalue(node->right);
    if(left>max)
        max=left;
    if(right>max)
        max=right;
    return max;
}

int minvalue(struct treenode*node)
{
    if(node==NULL)
        return 0;
    int min=node->data;
    int left=minvalue(node->left);
    int right=minvalue(node->right);
    if(left<min)
        min=left;
    if(right<min)
        min=right;
    return min;
}

int main()
{
    int data,ch;
    struct treenode *node=NULL;
    while(1)
    {
        printf(" 1.insertion \n 2.traverse \n 3.countnodes \n 4. count leaf nodes\n 5. count parent nodes\n 6. max value\n 7. min value\n");
        printf("enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("enter data to be inserted\n");
            scanf("%d",&data);
            node=insertion(node,data);
            break;
        case 2:
            traverse(node);
            break;
        case 3:
            printf("the number of nodes in given binary tree is %d\n",countnodes(node));
            break;
        case 4:
            printf("the number of leaf nodes in the given tree are %d\n",countleafnodes(node));
            break;
        case 5:
            printf("the number of parent nodes in the given tree are %d\n",countparentnodes(node));
            break;
        case 6:
            printf("the maximum value of node in given binary tree is %d\n",maxvalue(node));
            break;
        case 7:
            printf("the minimum value of node in given tree is %d\n",minvalue(node));
            break;
        case 8:
            exit(0);
        default:
            printf("invalid choice\n");
        }
    }
}

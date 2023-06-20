#include<stdio.h>
#include<stdlib.h>

typedef struct bst
{
    int data;
    struct bst *left,*right;
}*NODE;

int co=0,parent=0,leaf=0;

NODE create(int key)
{
    NODE newn=(NODE)malloc(sizeof(struct bst));
    newn->data=key;
    newn->left=newn->right=NULL;
    return newn;
}

NODE insert(NODE root,int key)
{
    if(root==NULL)
        root=create(key);
    else if(key>root->data)
        root->right=insert(root->right,key);
    else if(key<root->data)
        root->left=insert(root->left,key);
    return root;
}

NODE traverse(NODE root)
{
    if(root!=NULL)
    {
        traverse(root->left);
        printf("%d\t",root->data);
        traverse(root->right);
    }
    return root;
}

NODE count(NODE root)
{
    if(root==NULL)
        return root;
    else
    {
        co++;
        root->left=count(root->left);
        root->right=count(root->right);
        return root;
    }
}

NODE count_parent(NODE root)
{
    if(root==NULL)
        return root;
    else if(root->left!=NULL||root->right!=NULL)
    {
        parent++;
        root->left=count_parent(root->left);
        root->right=count_parent(root->right);
    }
    return root;
}

NODE count_leaf(NODE root)
{
    if(root==NULL)
        return root;
    else if(root->left==NULL && root->right==NULL)
        leaf++;
    root->left=count_leaf(root->left);
    root->right=count_leaf(root->right);
}

int max(NODE root)
{
    if (root->right==NULL)
    {
        printf("Max element is %d\n", root->data);
        return root->data;
    }
    else
        max(root->right);
}

int min(NODE root)
{
    if (root->left==NULL)
    {
        printf("Min element is %d\n", root->data);
        return root->data;
    }
    else
        min(root->left);
}

int search(NODE root,int key)
{
    if(root==NULL)
        return 0;
    else if(root->data==key)
        return 1;
    else if(root->data < key)
        return search(root->right,key);
    else if (root->data > key)
        return search(root->left,key);
}

NODE delete(NODE root,int key)
{
    if(root->data==key)
    {
        NODE temp;
        if(root->right==NULL)
        {
            temp = root->left;
            free(root);
            return temp;
        }
        else if(root->left==NULL)
        {
            temp = root->right;
            free(root);
            return temp;
        }
        else
        {
            int ma=max(root->left);
            root->data = max;
            temp = delete(root->left,ma);
            free(temp);
        }
    }
    else
    {
        if(key>root->data)
            root->right=delete(root->right,key);
        else if(key<root->data)
            root->left=delete(root->left,key);
    }
    return root;
}

int main()
{

    NODE root = NULL;
    int n,key,r,ma,mi;
    while (1)
    {
        printf("\n1->insert\t2->traverse\t3->count\t4->count parent nodes\t5->count leaf nodes\t6->max\t7->min\t8->Search\t9->delete\n");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("Enter key to insert\n");
            scanf("%d", &key);
            root = insert(root, key);
            break;
        case 2:
            root = traverse(root);
            break;
        case 3:
            co = 0;
            root = count(root);
            printf("count is %d\n", co);
            break;
        case 4:
            parent = 0;
            root = count_parent(root);
            printf("%d\n", parent);
            break;
        case 5:
            leaf = 0;
            root=count_leaf(root);
            printf("%d\n", leaf);
            break;
        case 6:
            ma = max(root);
            break;
        case 7:
            mi=min(root);
            break;
        case 8:
            printf("Enter key to search\n");
            scanf("%d", &key);
            r = search(root, key);
            if (r == 1)
                printf("Key found\n");
            else if (r == 0)
                printf("Key not found\n");
            break;
        case 9:
            printf("Enter key to delete\n");
            scanf("%d", &key);
            root = delete (root, key);
            printf("Element deleted\n");
            break;
        }
    }
    return 0;
}

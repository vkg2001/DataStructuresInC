#include <stdio.h>
#include <stdlib.h>
typedef struct binarytree
{
    int data;
    struct binarytree *Lchild;
    struct binarytree *Rchild;
} node;

int c, p, l;
node *getnode(int);
node *Insert(node *, int);
node *traverse(node *);
node *count(node *);
node *countparent(node *);
void countleaf(node *);
int search(node *, int);
node *getnode(int key)
{
    node *newn = (node *)malloc(sizeof(node));
    newn->data = key;
    newn->Lchild = NULL;
    newn->Rchild = NULL;

    return newn;
}
node *Insert(node *root, int key)
{
    if (root == NULL)
    {
        root = getnode(key);
    }
    else if (key > root->data)
    {
        root->Rchild = Insert(root->Rchild, key);
    }
    else if (key < root->data)
    {
        root->Lchild = Insert(root->Lchild, key);
    }

    return root;
}
node *traverse(node *root)
{
    if (root != NULL)
    {
        traverse(root->Lchild);
        printf("%d\n", root->data);
        traverse(root->Rchild);
    }

    return root;
}
node *count(node *root)
{
    node *temp = NULL;
    if (root == NULL)
    {
        return root;
    }
    else
    {
        c++;
        root->Lchild = count(root->Lchild);
        root->Rchild = count(root->Rchild);

        return root;
    }
}
node *countparent(node *root)
{
    if (root->Lchild != NULL || root->Rchild != NULL)
    {
        p++;
        root->Lchild = countparent(root->Lchild);
        root->Rchild = countparent(root->Rchild);
    }

    return root;
}
void countleaf(node *root)
{
    if (root == NULL)
    {
        return;
    }
    else if ((root->Lchild == NULL) && (root->Rchild == NULL))
    {
        l++;
    }
    countleaf(root->Lchild);
    countleaf(root->Rchild);
}
int max(node *root)
{
    if (root->Rchild == NULL)
    {
        printf("Max element is %d\n", root->data);
        return root->data;
    }
    else
    {
        max(root->Rchild);
    }
}
void min(node *root)
{
    if (root->Lchild == NULL)
    {
        printf("Min element is %d\n", root->data);
    }
    else
    {
        max(root->Lchild);
    }
}
int search(node *root, int key)
{
    if (root == NULL)
    {
        return 0;
    }
    else if (root->data == key)
    {
        return 1;
    }
    else if (root->data < key)
    {
        return search(root->Rchild, key);
    }
    else if (root->data > key)
    {
        return search(root->Lchild, key);
    }
}
node *delete (node *root, int key)
{
    if (root->data == key)
    {
        node *temp;
        if (root->Rchild == NULL)
        {
            temp = root->Lchild;
            free(root);
            return temp;
        }
        else if (root->Lchild == NULL)
        {
            temp = root->Rchild;
            free(root);
            return temp;
        }
        else
        {
            int m = max(root->Lchild);
            root->data = max;
            temp = delete (root->Lchild, m);
            free(temp);
        }
    }
    else
    {
        if (key > root->data)
        {
            root->Rchild = delete (root->Rchild, key);
        }
        else if (key < root->data)
        {
            root->Lchild = delete (root->Lchild, key);
        }
    }

    return root;
}

int main()
{

    node *root = NULL;
    int n, key, r, m;

    while (1)
    {
        printf("0->exit\n1->insert\n2->traverse\n3->count\n4->count parent nodes\n5->count leaf nodes\n6->max\n7->min\n8->Search\n9->delete\n");
        scanf("%d", &n);
        switch (n)
        {
        case 0:
            exit(0);
            break;
        case 1:
            printf("Enter key to insert\n");
            scanf("%d", &key);
            root = Insert(root, key);
            break;
        case 2:
            root = traverse(root);
            break;
        case 3:
            c = 0;
            root = count(root);
            printf("count is %d\n", c);
            break;

        case 4:
            p = 0;
            root = countparent(root);
            printf("%d\n", p);
            break;
        case 5:
            l = 0;
            countleaf(root);
            printf("%d\n", l);
            break;
        case 6:
            m = max(root);
            break;
        case 7:
            min(root);
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


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct student
{
    char name[10];
    int id;
    int sem;
    int cgpa;
    struct student *left;
    struct student *right;
}*NODE;

NODE getnode(char name[],int id,int sem,int cgpa)
{
    NODE newn;
    newn=(NODE)malloc(sizeof(struct student));
    newn->left=NULL;
    newn->right=NULL;
    strcpy(newn->name,name);
    newn->id=id;
    newn->sem=sem;
    newn->cgpa=cgpa;
    return newn;
}

NODE insert(NODE root,char name[],int id,int sem,int cgpa)
{
    if(root==NULL)
    {
        root=getnode(name,id,sem,cgpa);
        return root;
    }
    else if(root->id>id)
        root->left=insert(root->left,name,id,sem,cgpa);
    else if(root->id<id)
        root->right=insert(root->right,name,id,sem,cgpa);
    return root;
}

NODE search(NODE root,int id)
{
    if(root==NULL)
        printf("EMPTY!");
    else
    {
        if(root->id<id)
            root->right=search(root->right,id);
        else if(root->id>id)
            root->left=search(root->left,id);
       else if(root->id==id)
        {
            printf("Name : %s\n",root->name);
            printf("ID : %d\n",root->id);
            printf("Sem : %d\n",root->sem);
            printf("CGPA : %d\n",root->cgpa);
        }
    }
    return root;
}

NODE delete(NODE root,int id)
{
    if(root==NULL)
        printf("EMPTY!\n");
    NODE cur,par,p,suc;
    cur=root;
    par=NULL;
    while(cur!=NULL&&cur->id!=id)
    {
        par=cur;
        if(id>cur->id)
            cur=cur->right;
        else if(id<cur->id)
            cur=cur->left;
    }
    if(cur->left==NULL)
        p=cur->right;
    else if(cur->right==NULL)
        p=cur->left;
    else
    {
        suc=cur->right;
        while(suc->left!=NULL)
            suc=suc->left;
        suc->left=cur->left;
        p=cur->right;
    }
    if(par==NULL)
    {
        free(cur);
        return root;
    }
    if(cur==par->left)
        par->left=p;
    else if(cur==par->right)
        par->right=p;
    free(cur);
    return root;
}

void inorder(NODE root)
{
    if(root!=NULL)
    {
        inorder(root->left);
            printf("Name : %s\n",root->name);
            printf("ID : %d\n",root->id);
            printf("Sem : %d\n",root->sem);
            printf("CGPA : %d\n",root->cgpa);
        inorder(root->right);
    }
}

void preorder(NODE root)
{
    if(root!=NULL)
    {
            printf("Name : %s\n",root->name);
            printf("ID : %d\n",root->id);
            printf("Sem : %d\n",root->sem);
            printf("CGPA : %d\n",root->cgpa);
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
            printf("Name : %s\n",root->name);
            printf("ID : %d\n",root->id);
            printf("Sem : %d\n",root->sem);
            printf("CGPA : %d\n",root->cgpa);
    }
}

NODE parent(NODE root,int id)
{
    if(root->id==id)
    {
        printf("NO PARENT\n");
        return root;
    }
    else
    {
        NODE cur,par,gp;
        cur=root;
        par=NULL;
        while(cur!=NULL&&cur->id!=id)
        {
            gp=par;
            par=cur;
            if(id>cur->id)
                cur=cur->right;
            else if(id<cur->id)
                cur=cur->left;
        }
        if(cur==NULL)
            printf("NOT FOUND");
        else
        {
            printf("Parent details of selected node is\n");
            printf("Name : %s\n",par->name);
            printf("ID : %d\n",par->id);
            printf("Sem : %d\n",par->sem);
            printf("CGPA : %d\n",par->cgpa);
            printf("Grand Parent details of selected node is\n");
            printf("Name : %s\n",gp->name);
            printf("ID : %d\n",gp->id);
            printf("Sem : %d\n",gp->sem);
            printf("CGPA : %d\n",gp->cgpa);
        }
    }
    return root;
}

void adjacent(NODE root,int id)
{
    if(root==NULL||root->id==id)
        printf("There are no adjacent nodes\n");
    else
    {
        NODE cur,par,n;
        cur=root;
        par=NULL;
        while(cur!=NULL&&cur->id!=id)
        {
            par=cur;
            if(cur->id>id)
                cur=cur->left;
            else if(cur->id<id)
                cur=cur->right;
        }
        if(cur==NULL)
            printf("NOT FOUND");
        else if(par->left==cur)
        {
            n=par->right;
            printf("Adjacent node of %d is\n",id);
            printf("Name : %s\n",n->name);
            printf("ID : %d\n",n->id);
            printf("Sem : %d\n",n->sem);
            printf("CGPA : %d\n",n->cgpa);
        }
        else if(par->right==cur)
        {
            n=par->left;
            printf("Adjacent node of %d is\n",id);
            printf("Name : %s\n",n->name);
            printf("ID : %d\n",n->id);
            printf("Sem : %d\n",n->sem);
            printf("CGPA : %d\n",n->cgpa);
        }
    }
}

NODE lr(NODE root,int id)
{
    if(root->id==id)
    {
        inorder(root->left);
        inorder(root->right);
    }
    else if(root->id>id)
        root->left=lr(root->left,id);
    else if(root->id<id)
        root->right=lr(root->right,id);
    return root;
}

NODE level(NODE root,int id)
{
    int lvl=0;
    if(root==NULL)
        printf("EMPTY\n");
    if(root->id==id)
        lvl=0;
    else
    {
        NODE cur,par,n;
        cur=root;
        par=NULL;
        while(cur!=NULL&&cur->id!=id)
        {
            lvl++;
            if(cur->id>id)
                cur=cur->left;
            else if(cur->id<id)
                cur=cur->right;
        }
    }
    printf("Level of selected node is %d\n",lvl);
    return root;
}

void ancestor(NODE root,int id)
{
    if(root==NULL)
        printf("EMPTY");
    else
    {
        NODE cur,par,n;
        cur=root;
        printf("Ancestors of selected ID are\n");
        while(cur!=NULL&&cur->id!=id)
        {
            printf("Name : %s\n",cur->name);
            printf("ID : %d\n",cur->id);
            printf("Sem : %d\n",cur->sem);
            printf("CGPA : %d\n",cur->cgpa);
            if(cur->id>id)
                cur=cur->left;
            else if(cur->id<id)
                cur=cur->right;
        }
    }
}

void view(NODE root)
{
    NODE cur;
    cur=root;
    printf("Top View\n");
    printf("Name : %s\n",cur->name);
    printf("ID : %d\n",cur->id);
    printf("Sem : %d\n",cur->sem);
    printf("CGPA : %d\n",cur->cgpa);
    printf("Left View\n");
    while(cur!=NULL)
    {
        printf("Name : %s\n",cur->name);
        printf("ID : %d\n",cur->id);
        printf("Sem : %d\n",cur->sem);
        printf("CGPA : %d\n",cur->cgpa);
        cur=cur->left;
    }
    cur=root;
    printf("Right View\n");
    while(cur!=NULL)
    {
        printf("Name : %s\n",cur->name);
        printf("ID : %d\n",cur->id);
        printf("Sem : %d\n",cur->sem);
        printf("CGPA : %d\n",cur->cgpa);
        cur=cur->right;
    }
}

void bottom(NODE root)
{
    printf("Bottom View\n");
    if(root!=NULL)
    {
        bottom(root->left);
        if(root->left==NULL&&root->right==NULL)
        {
            printf("Name : %s\n",root->name);
            printf("ID : %d\n",root->id);
            printf("Sem : %d\n",root->sem);
            printf("CGPA : %d\n",root->cgpa);
        }
        bottom(root->right);
    }
}

void lbs(NODE root)
{
    int l=0,r=0;
    NODE cur;
    cur=root;
    while(cur!=NULL)
    {
        l++;
        cur=cur->left;
    }
        cur=root;
    while(cur!=NULL)
    {
        r++;
        cur=cur->right;
    }
    if(r>l)
        printf("Right tree is largest.\n");
    else if(l>r)
        printf("Left tree is largest.\n");
    else
        printf("Tree is balanced.\n");
}

int main()
{
    NODE root=NULL;
    int ch,id,sem,cgpa,sid,did,pid,aid,nid,lid,anid,max=0;
    char name[25];
    while(1)
    {
        printf("1.Insert\n");
        printf("2.Display inorder postorder and preorder\n");
        printf("3.Search\n");
        printf("4.Delete\n");
        printf("5.Display largest CGPA\n");
        printf("6.Display Parent node and Grand parent node\n");
        printf("7.Display Adjacent node\n");
        printf("8.Display RIGHT and LEFT tree\n");
        printf("9.Display Level\n");
        printf("10.Display Ancestors\n");
        printf("11.Display all views\n");
        printf("12.Find largest subtree\n");
        printf("13.EXIT\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
        {
            printf("Enter Name, ID, Semester & CGPA\n");
            scanf("%s %d %d %d",name,&id,&sem,&cgpa);
            if(max<cgpa)
                max=cgpa;
            root=insert(root,name,id,sem,cgpa);
            break;
        }
        case 2:
        {
            printf("Inorder\n");
            inorder(root);
            printf("\nPostorder\n");
            postorder(root);
            printf("\nPreorder\n");
            preorder(root);
            break;
        }
        case 3:
        {
            printf("Enter ID to search\n");
            scanf("%d",&sid);
            root=search(root,sid);
            break;
        }
        case 4:
        {
            printf("Enter ID to delete\n");
            scanf("%d",&did);
            root=delete(root,did);
            break;
        }
        case 5:
        {
            printf("%d\n",max);
            break;
        }
        case 6:
        {
            printf("Enter ID to display its parent & grand parent\n");
            scanf("%d",&pid);
            root=parent(root,pid);
            break;
        }
        case 7:
        {
            printf("Enter ID to display adjacent node\n");
            scanf("%d",&aid);
            adjacent(root,aid);
            break;
        }
        case 8:
        {
            printf("Enter ID to print left and right subtrees of\n");
            scanf("%d",&nid);
            root=lr(root,nid);
            break;
        }
        case 9:
        {
            printf("Enter the ID to display its level\n");
            scanf("%d",&lid);
            root=level(root,lid);
            break;
        }
        case 10:
        {
            printf("Enter ID to print its Ancestors\n");
            scanf("%d",&anid);
            ancestor(root,anid);
            break;
        }
        case 11:
        {
            view(root);
            bottom(root);
            break;
        }
        case 12:
            {
                lbs(root);
                break;
            }
        case 13:
            {
                exit(0);
                break;
            }
        }
    }
}

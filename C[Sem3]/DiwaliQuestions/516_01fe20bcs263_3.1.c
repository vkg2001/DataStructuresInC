#include<stdio.h>
#include<stdlib.h>

struct prolific_potion
{
     char ingredient[30];
     int quantity;
     struct prolific_potion * prev;
     struct prolific_potion * next;
};

yes=1;
no=2;

struct tree *insert(struct prolific_potion *node, char ingredient)
{
    if(node==NULL)
    {
        node=create(ingredient);
        return node;
    }
    else if(ingredient<node->ingredient)
    {
        node->prev=insert(node->prev,ingredient);
    }
    else if(ingredient>node->ingredient)
    {
        node->next=insert(node->next,ingredient);
    }
    return node;
};

struct prolific_potion *deleteN(struct prolific_potion *node, char ingredient)
{
    if(node==NULL)
    {
         node=create(ingredient);
        return node;
    }
    else
    {
        node->next==NULL;
        free(node);
    }
};

int main()
{
    int choice,a[30],point,fluxweed,bundles_of_knotgrass,leeches, Lacewing_flies,Bicorn_horn,ingredient;
    int top1=-1;
    for(; ;)
    {
        printf("Enter /n 1. Fluxweed/n2. Bundles of Knotgrass /n3. Leeches/n4. Lacewing flies/n5. Bicorn horn/n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:if(fluxweed>=30)
                   {
                       insert(ingredient);
                       printf("Ingredient successfully added.");
                    }
                 else
                   {
                       printf("Material not satisfied.\n");
                   }
            push(ingredient,a,&top1);
            case 2: if(bundles_of_knotgrass>=20)
            {
                    insert(ingredient);
                    printf("Ingredient successfully added.");
            }
               else
            {
                   printf("Material not satisfied.\n");
            }
            push(ingredient,a,&top1);
            case 3:if(leeches>=42)
               {
                     insert(ingredient);
                     printf("Ingredient successfully added.");
               }
                  else
               {
                     printf("Material not satisfied.\n");
                }
                push(ingredient,a,&top1);
                case 4:if( Lacewing_flies>=50)
                {
                    insert(ingredient);
                    printf("Ingredient added successfully.");
                }
                 else
               {
                     printf("Material not satisfied.\n");
               }
               push(ingredient,a,&top1);
          case 5:  if(Bicorn_horn>=9)
              {
                   insert(ingredient);
                   printf("Ingredient successfully added.");
               }
                else
               {
                    printf("Material not satisfied.\n");
                }
                push(ingredient,a,&top1);

                    break;

                    case 6:printf("Enter data to be popped =%d", pop(a,&top1));
                    break;
                }
    }
                if(ingredient==NULL)
                {
                    deleteN(ingredient);
                }
                else
                {
                    printf("Do you wish to edit ingredient? Select 1 for YES & 2 for NO\n");
                    scanf("%d",&point);
                    if(no)
                    {
                        exit;
                    }
                    else
                    {
                        printf("Enter the ingredient  which you want to edit...\n");
                        scanf("%c",&ingredient);
                        switch(ch);
                    }
                }
                printf("The POTION is ready, The dark army can now be defeated again!");
            }

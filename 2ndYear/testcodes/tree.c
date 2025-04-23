#include <stdio.h>
#include <stdlib.h>

struct node{
    char info;
    struct node *left,*right;
};

struct node* create()
{
    char ch;
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data(Enter n for no node):");
    scanf(" %c",&newnode->info);
    if(newnode->info=='n'||newnode->info=='N')
        return 0;
    else
    {
        printf("Enter the left child of the %c\n",newnode->info);
        newnode->left=create();
        printf("Enter the right child of %c\n",newnode->info);
        newnode->right=create();
        return newnode;
    }

}
int in_order(struct node* ptr)
{
    if(ptr==NULL)
        return 0;
    in_order(ptr->left);
    printf("%c->",ptr->info);
    in_order(ptr->right);

}
int pre_order(struct node *ptr)
{
    if(ptr==NULL)
        return 0;
    printf("%c->",ptr->info);
    pre_order(ptr->left);
    pre_order(ptr->right);
}
int post_order(struct node *ptr)
{
    if(ptr==NULL)
        return 0;
    post_order(ptr->left);
    post_order(ptr->right);
    printf("%c->",ptr->info);
}
int main()
{
    struct node *root=NULL;
    root=create();
    in_order(root);
    printf("\n");
    pre_order(root);
    printf("\n");
    post_order(root);
    return 0;
}
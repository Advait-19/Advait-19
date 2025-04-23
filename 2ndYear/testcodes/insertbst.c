#include <stdio.h>
#include <stdlib.h>

struct node{
    int info;
    struct node *left,*right;
};

struct node *create(int value){
    struct node *new;
    new=(struct node*)malloc(sizeof(struct node));
    new->info=value;
    new->left=NULL;
    new->right=NULL;
    return new;
}
struct node *insert(struct node *ptr,int value){
    if(ptr==NULL)
        return (create(value));
    else if(value<ptr->info)
        ptr->left=insert(ptr->left,value);
    else if(value>ptr->info)
        ptr->right=insert(ptr->right,value);
    return ptr;

}
void in_order(struct node *ptr){
    if(ptr==NULL)
        return;
    in_order(ptr->left);
    printf("%d->",ptr->info);
    in_order(ptr->right);
}
int main()
{
    struct node *root=NULL;
    root=insert(root,10);
    root=insert(root,20);
    root=insert(root,5);
    in_order(root);
    return 0;
}
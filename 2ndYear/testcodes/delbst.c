#include <stdio.h>
#include <stdlib.h>

struct node *search();

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
struct node *delete(struct node *ptr){
    if(ptr->left==NULL && ptr->right==NULL){
         free(ptr);
         return ptr;
    }
    else if(ptr->right!=NULL){
        struct node *temp=ptr->right;
        while(temp->left!=NULL){
            temp=temp->left;
        }
        ptr->info=temp->info;
        free(ptr);
        return temp;
    }    
    else if(ptr->left!=NULL){
        struct node *temp=ptr->left;
        while(temp->right!=NULL){
            temp=temp->right;
        }
        ptr->info=temp->info;
        free(ptr);
        return temp;
    }
    else{
        struct node *temp=ptr->left;
        while(temp->right!=NULL){
            temp=temp->right;
        }
        ptr->info=temp->info;
        ptr->left=search(ptr->left,temp->info);
    }
    return ptr;
}
struct node *search(struct node *ptr,int key){
    if(ptr==NULL)
        return ptr;
    if(key==ptr->info)
        return delete(ptr);
    else if(key<ptr->info)
        return ptr->left=search(ptr->left,key);
    else
        return ptr->right=search(ptr->right,key);

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
    int data,key;
    while(data!=-1){
    printf("Enter value of node(enter -1 for no node):");
    scanf("%d",&data);
    if(data==-1)
        break;
    root=insert(root,data);
    }
    in_order(root);
    printf("\nEnter the node to be deleted:");
    scanf("%d",&key);
    search(root,key);
    in_order(root);
    return 0;
}
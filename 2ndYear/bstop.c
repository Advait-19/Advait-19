#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *left, *right;
};

struct node *create(int value) {
    struct node *new;
    new = (struct node*)malloc(sizeof(struct node));
    new->info = value;
    new->left = NULL;
    new->right = NULL;
    return new;
}

struct node *insert(struct node *ptr, int value) {
    if (ptr == NULL)
        return create(value);
    else if (value < ptr->info)
        ptr->left = insert(ptr->left, value);
    else if (value > ptr->info)
        ptr->right = insert(ptr->right, value);
    return ptr;
}

struct node *findMin(struct node *ptr) {
    while (ptr->left != NULL)
        ptr = ptr->left;
    return ptr;
}

struct node *findMax(struct node *ptr) {
    while (ptr->right != NULL)
        ptr = ptr->right;
    return ptr;
}

int count(struct node *ptr)
{
    if(ptr==NULL)
        return 0;
    else
    {
        return 1 + count(ptr->left) + count(ptr->right);
    }

}

struct node *delete(struct node *ptr, int key) {
    if (ptr == NULL)
        return ptr;
    if (key < ptr->info)
        ptr->left = delete(ptr->left, key);
    else if (key > ptr->info)
        ptr->right = delete(ptr->right, key);
    else {
        if (ptr->left == NULL) {
            struct node *temp = ptr->right;
            free(ptr);
            return temp;
        } else if (ptr->right == NULL) {
            struct node *temp = ptr->left;
            free(ptr);
            return temp;
        }

        struct node *temp = findMax(ptr->left);
        ptr->info = temp->info;
        ptr->left = delete(ptr->left, temp->info);
    }
    return ptr;
}

struct node *search(struct node *ptr,int key){
    if(ptr==NULL)
        return ptr;
    if(key==ptr->info)
        return ptr;
    else if(key<ptr->info)
        return search(ptr->left,key);
    else
        return search(ptr->right,key);

}

void in_order(struct node *ptr) {
    if (ptr == NULL)
        return;
    in_order(ptr->left);
    printf("%d -> ", ptr->info);
    in_order(ptr->right);
}
int pre_order(struct node *ptr)
{
    if(ptr==NULL)
        return 0;
    printf("%d->",ptr->info);
    pre_order(ptr->left);
    pre_order(ptr->right);
}
int post_order(struct node *ptr)
{
    if(ptr==NULL)
        return 0;
    post_order(ptr->left);
    post_order(ptr->right);
    printf("%d->",ptr->info);
}

int main() {
    struct node *root = NULL;
    int data, key;
    int choice;
    while (1) {
        printf("Enter value of node (enter -1 for no node): ");
        scanf("%d", &data);
        if (data == -1)
            break;
        root = insert(root, data);
    }

    do{
        printf("\n1.Insertion\n2.Deletion\n3.Traversal\n4.Search");
        printf("\n5.Max element\n6.Min element\n7.Count\n8.Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                printf("\nEnter value of node: ");
                scanf("%d", &data);
                root=insert(root,data);
                break;
            }
            case 2:{
                printf("\nEnter the node to be deleted:");
                scanf(" %d",&key);
                delete(root,key);
                break;
            }
            case 3:{
                printf("\nIn-order traversal of tree:");
                in_order(root);
                printf("\nPre-order traversal of tree:");
                pre_order(root);
                printf("\nPost-order traversal of tree:");
                post_order(root);
                break;
            }
            case 4:{
                printf("\nEnter the node to be searched:");
                scanf(" %d",&key);
                struct node *ptr=search(root,key);
                if(ptr==NULL)
                    printf("\nElement is not found");
                else
                    printf("\nElement is found in the tree");
                break;
            }
            case 5:{
                struct node *ptr=findMax(root);
                printf("\nMaximum element of the tree is:%d",ptr->info);
                break;
            }
            case 6:{
                struct node *ptr=findMin(root);
                printf("\nMinimum element of the tree is:%d",ptr->info);
                break;
            }
            case 7:{
                int node_count=count(root);
                printf("Number of nodes in the tree:%d",node_count);
                break;
            }
            case 8:
            printf("\nPlease visit next time\nGoodbye\n");
            exit(1);

            default:
                break;

        }
    }
    while(choice!=8);

    return 0;
}
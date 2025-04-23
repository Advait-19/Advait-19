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

// Function to find the minimum value node in a subtree
struct node *findMin(struct node *ptr) {
    while (ptr->left != NULL)
        ptr = ptr->left;
    return ptr;
}

// Function to delete a node in the tree
struct node *delete(struct node *ptr, int key) {
    if (ptr == NULL)
        return ptr;

    // Traverse the tree to find the node to delete
    if (key < ptr->info)
        ptr->left = delete(ptr->left, key);
    else if (key > ptr->info)
        ptr->right = delete(ptr->right, key);
    else {
        // Node with only one child or no child
        if (ptr->left == NULL) {
            struct node *temp = ptr->right;
            free(ptr);
            return temp;
        } else if (ptr->right == NULL) {
            struct node *temp = ptr->left;
            free(ptr);
            return temp;
        }

        // Node with two children: get the inorder successor (smallest in the right subtree)
        struct node *temp = findMin(ptr->right);
        ptr->info = temp->info;
        ptr->right = delete(ptr->right, temp->info);
    }
    return ptr;
}

// Function to perform in-order traversal
void in_order(struct node *ptr) {
    if (ptr == NULL)
        return;
    in_order(ptr->left);
    printf("%d -> ", ptr->info);
    in_order(ptr->right);
}

int main() {
    struct node *root = NULL;
    int data, key;

    // Build the tree
    while (1) {
        printf("Enter value of node (enter -1 for no node): ");
        scanf("%d", &data);
        if (data == -1)
            break;
        root = insert(root, data);
    }

    printf("In-order traversal of the tree: ");
    in_order(root);
    printf("\n");

    // Delete a node
    printf("Enter the node to be deleted: ");
    scanf("%d", &key);
    root = delete(root, key);

    printf("In-order traversal after deletion: ");
    in_order(root);
    printf("\n");

    return 0;
}


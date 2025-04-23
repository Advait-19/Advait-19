#include <stdio.h>
#include <stdlib.h>
struct Node{
    int row, col, value;
    struct Node* next;
};

void create(struct Node **Head){
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    *Head=ptr;
    int nonzero;
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &ptr->row, &ptr->col);
    printf("Enter the number of non-zero elements: ");
    scanf("%d", &nonzero);
    ptr->value = nonzero;
    ptr->next = NULL;
    int i=0;
    while(i!=nonzero){
        struct Node *ptr1=(struct Node*)malloc(sizeof(struct Node));
        printf("Enter the row, column, and value for each non-zero element:");
        scanf("%d %d %d",&ptr1->row,&ptr1->col,&ptr1->value);
        ptr1->next=NULL;
        ptr->next=ptr1;
        ptr=ptr->next;
        i++;
    }
}

void display(struct Node* Head){
    struct Node* temp = Head;
    printf("Representation of sparse matrix:\n");
    while(temp != NULL){
        printf("%d %d %d\n", temp->row, temp->col, temp->value);
        temp = temp->next;
    }
}

void main(){
    struct Node* Head = NULL;
    create(&Head);
    display(Head);

    struct Node *temp;
    while (Head != NULL){
        temp = Head;
        Head = Head->next;
        free(temp);
    }
}
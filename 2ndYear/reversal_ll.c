#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int Data;
    struct Node *Next,*Prev;
};

void create(struct Node **Head)
{
    struct Node *ptr,*ptr1;
    ptr=(struct Node*)malloc(sizeof(struct Node));
    *Head=ptr;
    if (ptr == NULL) {
            printf("Memory allocation failed\n");
            exit(1);
        }
    printf("Enter the value of first node:");
    scanf("%d",&ptr->Data);
    ptr->Next=NULL;
    ptr->Prev=NULL;
    char ch;
    printf("Do you have another data?(y/n): ");
    scanf(" %c",&ch);
    while(ch=='y')
    {
        ptr1=(struct Node*)malloc(sizeof(struct Node));
        if (ptr1 == NULL) {
            printf("Memory allocation failed\n");
            exit(1);
        }
        printf("Enter the value of next node: ");
        scanf("%d",&ptr1->Data);
        ptr1->Next=NULL;
        ptr1->Prev=ptr;
        ptr->Next=ptr1;
        ptr=ptr->Next;
        printf("Do you have another data?(y/n): ");
        scanf(" %c",&ch);
    }
}

void display(struct Node *Head)
{
    struct Node *ptr;
    ptr=Head;
    ptr->Prev=NULL;
    if(ptr==NULL){
        printf("Absolutely nothing");
        return;
    }
    while(ptr->Next!=NULL)
    {
        ptr=ptr->Next;
    }
    while(ptr!=NULL){
        printf("%d ",ptr->Data);
        ptr=ptr->Prev;
    }
    printf("\n");
}

int main()
{
    struct Node *Head=NULL;
    create(&Head);
    printf("\nThe elements of the new node are(in reversal):\n");
    display(Head);

    struct Node *temp;
    while (Head != NULL) {
        temp = Head;
        Head = Head->Next;
        free(temp);
    }
    return 0;
}
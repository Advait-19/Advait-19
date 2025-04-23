#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int Data;
    struct Node *Next;
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
    if(ptr==NULL){
        printf("Absolutely nothing");
        return;
    }
    while(ptr!=NULL)
    {
        printf("%d ",ptr->Data);
        ptr=ptr->Next;
    }
    printf("\n");
}

void insert(struct Node **Head,int data,int pos,int count)
{
    struct Node *New=(struct Node*)malloc(sizeof(struct Node));
    New->Data=data;
    New->Next=NULL;
    if(pos==1){
        New->Next=*Head;
        *Head=New;
    }
    else if(pos==count+1){
        struct Node *temp;
        temp=*Head;
        while(temp->Next!=NULL){
            temp=temp->Next;
        }
        if(temp==NULL){
            printf("Position does not exist");
            return;
        }
        New->Next=NULL;
        temp->Next=New;
    }
    else{
        struct Node *temp;
        temp=*Head;
        int i=1;
        while(i<(pos-1)){
            temp=temp->Next;
            i++;
        }
        if(temp==NULL){
            printf("Position does not exist");
            return;
        }
        New->Next=temp->Next;
        temp->Next=New;
    }
}

int count(struct Node *Head)
{
    struct Node *ptr;
    ptr=Head;
    int number;
    while(ptr!=NULL)
    {
        number++;
        ptr=ptr->Next;
    }
    return number;
}

void main()
{
    struct Node *Head=NULL;
    int info,pos;
    create(&Head);
    printf("\nThe elements of the node are:\n");
    display(Head);
    printf("Enter the data and position:");
    scanf("%d%d",&info,&pos);
    int value=count(Head);
    insert(&Head,info,pos,value);
    printf("\nThe elements of the new node are:\n");
    display(Head);

    struct Node *temp;
    while (Head != NULL) {
        temp = Head;
        Head = Head->Next;
        free(temp);
    }
}
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

void delete(struct Node **Head,int pos,int count)
{
    if(pos==1){
        struct Node *Temp;
        Temp=*Head;
        *Head=Temp->Next;
        free(Temp);
        return;
    }
    else if(pos<1||pos>count){
        printf("Position does not exist");
        return;
    }
    else if(pos==count){
        struct Node *temp,*ptr;
        temp=*Head;
        ptr=*Head;
        while(temp->Next->Next!=NULL){
            temp=temp->Next;
        }
        ptr=temp->Next;
        temp->Next=NULL;
        free(ptr);
    }
    else{
        struct Node *temp,*ptr;
        temp=*Head;
        ptr=*Head;
        int i=1;
        while(i<(pos-1)){
            temp=temp->Next;
            i++;
        }
        if(temp==NULL){
            printf("Position does not exist");
            return;
        }
        ptr=temp->Next;
        temp->Next=ptr->Next;
        free(ptr);
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

int main()
{
    struct Node *Head=NULL;
    int pos;
    create(&Head);
    printf("\nThe elements of the node are:\n");
    display(Head);
    printf("Enter the position:");
    scanf("%d",&pos);
    int value=count(Head);
    delete(&Head,pos,value);
    printf("\nThe elements of the new node are:\n");
    display(Head);

    struct Node *temp;
    while (Head != NULL) {
        temp = Head;
        Head = Head->Next;
        free(temp);
    }
    return 0;
}


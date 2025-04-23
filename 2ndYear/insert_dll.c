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
int count(struct Node *Head)
{
    struct Node *ptr;
    ptr=Head;
    int number=0;
    while(ptr!=NULL)
    {
        number++;
        ptr=ptr->Next;
    }
    return number;
}
void display(struct Node *Head)
{
    struct Node *ptr;
    ptr=Head;
    if(ptr==NULL){
        printf("Absolutely nothing\n");
        return;
    }
    while(ptr!=NULL){
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
    New->Prev=NULL;
    if(pos==1){
        New->Next=*Head;
        (*Head)->Prev=New;
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
        temp->Next=New;
        New->Prev=temp;
    }
    else{
        struct Node *temp,*ptr1;
        temp=*Head;
        int i=1;
        while(i<pos){
            temp=temp->Next;
            i++;
        }
        if(temp==NULL){
            printf("Position does not exist");
            return;
        }
        ptr1=temp->Prev;
        ptr1->Next=New;
        New->Prev=ptr1;
        New->Next=temp;
        temp->Prev=New;
    }
}
void delete(struct Node **Head,int pos,int count)
{
    if(pos==1){
        struct Node *Temp;
        Temp=*Head;
        *Head=Temp->Next;
        if(*Head!=NULL){
            (*Head)->Prev=NULL;
        }
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
        while(temp->Next!=NULL){
            temp=temp->Next;
        }
        if(temp==NULL){
            printf("Position does not exist");
            return;
        }
        ptr=temp->Prev;
        ptr->Next=NULL;
        free(temp);
    }
    else{
        struct Node *temp,*ptr,*new;
        temp=*Head;
        ptr=*Head;
        int i=1;
        while(i<(pos-1)){
            temp=temp->Next;
            i++;
        }
        if(temp==NULL||temp->Next==NULL){
            printf("Position does not exist");
            return;
        }
        ptr=temp->Next;
        new=ptr->Next;
        temp->Next=new;
        new->Prev=temp;
        free(ptr);
    }
}
int main()
{
    struct Node *Head=NULL;
    int choice;
    create(&Head);
    do{
        printf("\n1.Insertion\n2.Deletion\n3.Traversal\n4.Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                int info,pos;
                printf("\nThe elements of the node are:\n");
                display(Head);
                printf("Enter the data and position:");
                scanf("%d%d",&info,&pos);
                int value=count(Head);
                insert(&Head,info,pos,value);
                printf("The elements of the new node are:\n");
                display(Head);
                break;
            }
            case 2:{
                int pos;
                printf("\nThe elements of the node are:\n");
                display(Head);
                printf("Enter the position:");
                scanf("%d",&pos);
                int value=count(Head);
                delete(&Head,pos,value);
                printf("The elements of the new node are:\n");
                display(Head);
                break;
            }
            case 3:{
                printf("\nThe elements of the node are:\n");
                display(Head);
                break;
            }
            case 4:
            printf("\nPlease visit next time\nGoodbye\n");
            exit(0);

            default:
                break;

        }
    }
    while(choice!=4);
        
    struct Node *temp;
    while (Head != NULL){
        temp = Head;
        Head = Head->Next;
        free(temp);
    }
    return 0;
    
}
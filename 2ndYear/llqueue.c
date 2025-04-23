#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct Node
{
    int data;
    struct Node *Next;
}*front=NULL,*rear=NULL;

int is_empty(){
    if(front==NULL && rear==NULL)
        return 1;
    else
        return 0;
}

void enqueue(int value){
    struct Node *new=(struct Node*)malloc(sizeof(struct Node));
    if(is_empty()){
    new->data=value;
    new->Next=NULL;
    new->Next=front;
    front=new;
    rear=new;
    }
    else{
    new->data=value;
    new->Next=NULL;
    rear->Next=new;
    rear=new;
    }
}

int dequeue(){
    struct Node *ptr;
    int temp;
    if(is_empty()){
        printf("queue underflow\n");
        return 1;
    }
    else if(front==rear){
        temp=front->data;
        front=NULL;
        rear=NULL;
        printf("The deleted element is: %d\n",temp);
        free(ptr);
        return temp;
    }
    else{
        temp=front->data;
        ptr=front;
        printf("The deleted element is: %d\n",temp);
        front=front->Next;
        free(ptr);
        return temp;
    }
}

void traverse(){
    if (is_empty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("The queue formed is: \n");
    struct Node *ptr=front;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->Next;
    }
}
int main(){
    int choice;
    do{
        printf("\n1.Enqueue\n2.Dequeue\n3.Traversal\n4.Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                int data;
                printf("Enter the data: ");
                scanf("%d",&data);
                enqueue(data);
                traverse();
                break;
            }
            case 2:{
                dequeue();
                traverse();
                break;
            }
            case 3:{
                printf("\nThe elements of the queue are:\n");
                traverse();
                break;
            }
            case 4:
            printf("\nPlease visit next time\nGoodbye\n");
            exit(1);

            default:
                break;

        }
    }
    while(choice!=4);{}
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#define MAX 20

int front=-1;
int rear=-1;
int queue[MAX];

int is_empty(){
    if(front==-1 && rear==-1){
        return 1;
    }
    else
     return 0; 
}
int is_full(){
    if(rear==MAX-1){
        return 1;
    }
    else
     return 0;
}
void enqueue(int value){
    if(is_full()){
        printf("Queue overflow\n");
        return;
    }
    else if(is_empty()){
        front++;
        rear++;
        queue[front]=value;
    }
    else{
        rear++;
        queue[rear]=value;
    }
}
int dequeue(){
    if(is_empty()){
        printf("queue underflow\n");
        return -1;
    }
    else if(front==rear){
        front=-1;
        rear=-1;
        return 0;
    }
    else{
        int temp=queue[front];
        front++; 
        return temp;
    }
}
void traverse(){
    if(is_empty()){
        printf("Empty queue\n");
        return;
    }
    printf("The queue formed is:\n");
    for(int i=front;i<=rear;i++){
        printf("%d ",queue[i]);
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

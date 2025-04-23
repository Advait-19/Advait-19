#include <stdio.h>
#define max 100

int top=-1;
int stack[max];

int front=-1;
int rear=-1;
int queue[max];

void push(int data){
    if(top==max-1){
        printf("stack overflow\n");
    }
    top++;
    stack[top]=data;
}

int pop(){
    if(top==-1){
        printf("stack underflow\n");
        return 0;
    }
    else{
        int temp=stack[top];
        top--;
        return temp;
    }
}
void enqueue(int value){
    if(rear==max-1){
        printf("Queue overflow\n");
        return;
    }
    else if(front==-1 && rear==-1){
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
    int temp;
    if(front==-1 && rear==-1){
        printf("queue underflow\n");
        return 0;
    }
    else if(front==rear){
        int temp=queue[front];
        front=-1;
        rear=-1;
        return temp;
    }
    else{
        int temp=queue[front];
        front++; 
        return temp;
    }
    
}
int main(){
    int data,i;
    while(1){
        printf("Enter the data for queue(-1 for no data): ");
        scanf("%d",&data);
        if(data==-1)
            break;
        enqueue(data);
    }
    while(front!=-1 && rear!=-1){
        int temp=dequeue();
        push(temp);
    }
    while(top!=-1){
        int temp=pop();
        enqueue(temp);
    }
    printf("Elements of queue in reverse:");
    for(i=front;i<=rear;i++){
        printf("%d ",queue[i]);
    }
    return 0;
}
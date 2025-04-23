#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct Node
{
    int data;
    struct Node *Next;
}*Top=NULL;

int is_empty(){
    return Top==NULL;
}

void push(int value){
    struct Node *new=(struct Node*)malloc(sizeof(struct Node));
    new->data=value;
    new->Next=NULL;
    new->Next=Top;
    Top=new;
}

int pop(){
    struct Node *ptr;
    int temp;
    if(is_empty()){
        printf("stack underflow\n");
        return 1;
    }
    else{
        temp=Top->data;
        ptr=Top;
        printf("The popped element is: ");
        printf("%d \n",temp);
        Top=Top->Next;
        free(ptr);
        return temp;
    }
}

int peek(){
    if(is_empty()){
        return 1;
    }
    else{
        return Top->data;
    }
}

void traverse(){
    if (is_empty()) {
        printf("Stack is empty.\n");
        return;
    }
    printf("The stack formed is: \n");
    struct Node *ptr=Top;
    while(ptr!=NULL){
        printf("%d\n",ptr->data);
        ptr=ptr->Next;
    }
}

int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    traverse();
    pop();

    int top_element=peek();
    printf("The top element is: %d\n",top_element);
    traverse();

    struct Node *current = Top;
    struct Node *temp;
    while (current != NULL) {
        temp = current->Next;
        free(current);
        current = temp;
    }
    Top = NULL;
}


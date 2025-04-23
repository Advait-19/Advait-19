#include <stdio.h>
#define MAX 100

int stack[MAX];
int top=-1;

int is_empty(){
    return top==-1;
}

int is_full(){
    return top==MAX-1;
}

void push(int data){
    if(is_full()){
        printf("stack overflow\n");
    }
    top++;
    stack[top]=data;
}

int pop(){
    if(is_empty()){
        printf("stack underflow\n");
    }
    else{
        int temp=stack[top];
        printf("The popped element is: ");
        printf("%d \n",temp);
        top--;
        return temp;
    }
}

int peek(){
    if(is_empty()){
        return 1;
    }
    else{
        return stack[top];
    }
}

void traverse(){
    if (is_empty()) {
        printf("Stack is empty.\n");
        return;
    }
    printf("The stack formed is: \n");
    for(int i=0;i<=top;i++){
        printf("%d\n",stack[i]);
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
    printf("The top element is %d\n",top_element);
    traverse();
}
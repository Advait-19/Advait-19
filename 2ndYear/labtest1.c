#include <stdio.h>
#define MAX 20

int top=-1;
int stack[MAX];

int is_empty(){
    if(top==-1){
        return -1;
    }
    else
        return 0;
}

int is_full(){
    if(top==MAX-1){
        return -1;
    }
    else
        return 0;
}

void push(int value){
    if(is_full()){
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack[top]=value;
}

int pop(){
    if(is_empty()){
        printf("Stack Underflow\n");
        return -1;
    }
    int temp=stack[top];
    top--;
    return temp;
}

int main(){
    push(10);
    push(20);
    push(30);
    printf("The stack formed is:\n");
    for(int i=0;i<top;i++){
        printf("%d ",stack[i]);
    }
    pop();
    int top_element=pop();
    printf("\nThe top element is %d",top_element);
    return 0;
}

#include <stdio.h>
#define max 100

int top=-1;
int stack[max];
int top1=-1;
int stack1[max];

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
void push1(int data){
    if(top==max-1){
        printf("stack overflow\n");
    }
    top++;
    stack1[top]=data;
}

int pop1(){
    if(top==-1){
        printf("stack underflow\n");
        return 0;
    }
    else{
        int temp=stack1[top];
        top--;
        return temp;
    }
}

int main(){
    int data,count=0;
    while(1){
        printf("Enter the data for queue(-1 for no data): ");
        scanf("%d",&data);
        if(data==-1)
            break;
        push(data);
        count++;
    }
    if(count%2==0){
        for(int i=1;i<=count/2;i++){
            int temp=pop();
            push1(temp);
        }
        int mid=pop();
        printf("Middle element is: %d",mid);
    }
    else{
        for(int i=1;i<=count/2;i++){
            int temp=pop();
            push1(temp);
        }
        int mid=pop();
        printf("Middle element is: %d",mid);
    }
    return 0;
}


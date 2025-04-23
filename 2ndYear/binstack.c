#include <stdio.h>
#include <math.h>
#define MAX 100

int top=-1;
int stack[MAX];

int is_empty(){
    return top==-1;
}

int is_full(){
    return top==MAX-1;
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
        return 1;
    }
    int temp=stack[top];
    top--;
    return temp;
}

int main()
{
    int num,bin=0,x;
    int n=-1;
    printf("Enter the decimal number: ");
    scanf("%d",&num);
    if(num==0){
        printf("The binary conversion of given decimal number is: 0\n");
    }

    while(num>0){
        x=num%2;
        push(x);
        n++;
        num/=2;
    }

    printf("The binary conversion of given decimal number is: ");
    while (!is_empty()) {
        printf("%d", pop());
    }
    printf("\n");
    
    return 0;
}
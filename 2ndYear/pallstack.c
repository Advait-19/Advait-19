#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

char stack[MAX]={'\0'};
int top=-1;

void push(char value){
    if(top==MAX-1){
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack[top]=value;
}

char pop(){
    if(top==-1){
        printf("Stack Underflow\n");
        return -1;
    }
    char temp=stack[top];
    top--;
    return temp;
}

int main(){
    char str[MAX]={'\0'};
    int len=0;
    printf("Enter the string: ");
    scanf("%s",str);
    len=strlen(str);
    int i=0;
    while(i<len){
        push(tolower(str[i]));
        i++;
    }
    i=0;
    while(i<len){
        if(tolower(str[i])!=pop()){
            break;
        }
        i++;
    }
    if(i==len){
        printf("Pallindrome string\n");
    }
    else{
        printf("Non-pallindrome string\n");
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int semester,roll;
    struct Node* next,*prev;
    char name[50],section;
    float cgpa;
} *master=NULL,*lowcgpa=NULL;

void create(struct Node **master){
    struct Node *ptr,*ptr1;
    ptr=(struct Node*)malloc(sizeof(struct Node));
    *master=ptr;
    printf("Enter the name: ");
    scanf("%s",&ptr->name);
    printf("Enter semester: ");
    scanf("%d",&ptr->semester);
    printf("Enter roll number: ");
    scanf("%d",&ptr->roll);
    printf("Enter the section: ");
    scanf(" %c",&ptr->section);
    printf("Enter CGPA: ");
    scanf("%f",&ptr->cgpa);
    ptr->next=NULL;
    ptr->prev=NULL;
    char ch;
    printf("Another student details?(y/n):");
    scanf(" %c",&ch);
    while(ch=='y')
    {
        ptr1=(struct Node*)malloc(sizeof(struct Node));
        if (ptr1 == NULL) {
            printf("Memory allocation failed\n");
            exit(1);
        }
        printf("Enter the name: ");
        scanf("%s",&ptr1->name);
        printf("Enter semester: ");
        scanf("%d",&ptr1->semester);
        printf("Enter roll number: ");
        scanf("%d",&ptr1->roll);
        printf("Enter the section: ");
        scanf(" %c",&ptr1->section);
        printf("Enter CGPA: ");
        scanf("%f",&ptr1->cgpa);
        ptr1->next=NULL;
        ptr->next=ptr1;
        ptr1->prev=ptr;
        ptr=ptr->next;
        printf("Another student details?(y/n):");
        scanf(" %c",&ch);
    }
}

void deletenadd(struct Node **ptr,struct Node **lowcgpa){
    struct Node *temp = *ptr;

    // Detach the node from the master list
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    // If the node to delete is the head of the master list, update the head
    if (temp == master) {
        master = temp->next;
    }

    // Add the node to the lowcgpa list
    temp->next = *lowcgpa;
    if (*lowcgpa != NULL) {
        (*lowcgpa)->prev = temp;
    }
    *lowcgpa = temp;
    temp->prev = NULL;
}

void update(struct Node **master,struct Node **lowcgpa){
    struct Node *ptr=*master;
    while(ptr!=NULL){
        struct Node *nextptr=ptr->next;
        if(ptr->cgpa<6){
            deletenadd(&ptr,lowcgpa);
        }
        else if(ptr->cgpa>=6 && ptr->cgpa<7){
            ptr->semester++;
            ptr->section='A';
        }
        else if(ptr->cgpa>=7 && ptr->cgpa<8){
            ptr->semester++;
            ptr->section='B'; 
        }
        else if(ptr->cgpa>=8 && ptr->cgpa<9){
            ptr->semester++;
            ptr->section='C';
        }
        else if(ptr->cgpa>=9 && ptr->cgpa<10){
            ptr->semester++;
            ptr->section='D';
        }
        ptr=ptr->next;
    }
}

void display(struct Node *head)
{
    struct Node *ptr;
    ptr=head;
    if(ptr==NULL){
        printf("Absolutely nothing\n");
        return;
    }
    while(ptr!=NULL){
        printf("Name: ");
        printf("%s\n",ptr->name);
        printf("Semester: ");
        printf("%d\n",ptr->semester);
        printf("Roll number: ");
        printf("%d\n",ptr->roll);
        printf("Section: ");
        printf(" %c\n",ptr->section);
        printf("CGPA: ");
        printf("%f\n",ptr->cgpa);
        ptr=ptr->next;
    }
    printf("\n");
}

int main(){
    create(&master);
    update(&master,&lowcgpa);
    printf("Master Linked List:\n");
    display(master);
    printf("Low CGPA Linked List:\n");
    display(lowcgpa);  
    return 0; 
}


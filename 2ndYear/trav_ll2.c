#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int Data;
    struct Node *Next;
};

void traverse(struct Node *Head)
{
    struct Node *ptr;
    ptr=Head;
    while(ptr!=NULL)
    {
        printf("%d ",ptr->Data);
        ptr=ptr->Next;
    }
}

void main()
{
    int n;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    struct Node *Head,*ptr;
    printf("Enter the elements: ");
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            Head=(struct Node*)malloc(sizeof(struct Node));
            ptr=Head;
        }
        else{
            ptr->Next=(struct Node*)malloc(sizeof(struct Node));
            ptr=ptr->Next;
        }
        scanf("%d",&ptr->Data);
    }
    ptr->Next=NULL;
    printf("The elements of the node are:\n");
    traverse(Head);

    struct Node *temp;
    while (Head != NULL) {
        temp = Head;
        Head = Head->Next;
        free(temp);
}
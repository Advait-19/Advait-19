#include <stdio.h>
int insert(int a[],int data,int size,int pos)
{
    if(pos<1||pos>size+1)
    {
        return -1;
    }
    else{
        for(int i=size-1;i>(pos-1)-1;i--)
        {
            a[i+1]=a[i];
        }
        a[pos-1]=data;
        return size+1;
    }
}
int del(int a[],int size,int pos)
{
    if(pos<1||pos>size)
    {
        return -1;
    }
    else{
        for(int i=pos-1;i<size;i++)
        {
            a[i]=a[i+1];
        }
        return size-1;
    }
}
int search(int a[],int key,int size)
{
    for(int i=0;i<size;i++)
    {
        if(a[i]==key){
            return i+1;
        }
    }
    return -1;
}
void traverse(int a[],int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d ",a[i]);
    }
}
int main()
{
    int n,choice;
    printf("Enter size of your array:");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\nMenu options:\n");
    printf("1.Insertion\n");
    printf("2.Deletion\n");
    printf("3.Search\n");
    printf("4.Traversal\n");
    printf("Enter your option:");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:{
        int value,position;
        printf("Enter data and its position:");
        scanf("%d %d",&value,&position);
        int newsize=insert(arr,value,n,position);
        if(newsize==-1){
            printf("Invalid input");
        }
        else{
            for(int i=0;i<newsize;i++)
            {
                printf("%d ",arr[i]);
            }
        }
        break;
        }

        case 2:{
        int position;
        printf("Enter the positon:");
        scanf("%d",&position);
        int newsize=del(arr,n,position);
        if(newsize==-1){
            printf("Invalid input");
        }
        else{
            for(int i=0;i<newsize;i++)
            {
                printf("%d ",arr[i]);
            }
        }
        break;
        }

        case 3:{
        int info;
        printf("Enter the element to search:");
        scanf("%d",&info);
        int find=search(arr,info,n);
        if(find==-1){
            printf("Element not found");
        }
        else{
            printf("Element found at %d position",find);
        }
        break;
        }

        case 4:{
        printf("Elements of the array are: ");
        traverse(arr,n);
        break;
        }

        default:
        printf("Invalid input");
    }
    return 0;

}
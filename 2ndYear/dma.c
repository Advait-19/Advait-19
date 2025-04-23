#include <stdio.h>
#include <stdlib.h>
int prime_sum(int *arr,int a)
{
    int j,k,f;
    int sum=0;
    for(j=0;j<a;j++)
    {
        f=0;
        for(k=1;k<=arr[j];k++)
        {
            if(arr[j]%k==0)
            {
                f++;
            }
        }
        if(f==2)
    {
        sum=sum+arr[j];
    }

    }
    return sum;
}

    
void main()
{
    int *ptr;
    int n;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    ptr=(int*)malloc(n*sizeof(int));
    printf("Enter the elements:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&ptr[i]);
    }
   int sum_p=prime_sum(ptr,n);
   printf("Sum of all prime elements is %d",sum_p);
   free(ptr);
}
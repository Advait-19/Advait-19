#include <stdio.h>
int sort(int n,int a[])
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }  
        }
    }
    printf("\n");
    for(i=0;i<n;i++)
    printf("%d ",a[i]);
    return 0;
}
void main()
{
    int i,a[]={46,67,32,54,21};
    int n=5;
    for(i=0;i<n;i++)
    printf("%d ",a[i]);
    sort(n,a);
}

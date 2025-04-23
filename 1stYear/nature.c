#include <stdio.h>
void main()
{
    int n;
    printf("Show any number here\n");
    scanf("%d",&n);
    if(n>0)
    {
        printf("Postive number\n");
    }
    else if(n==0)
    {
        printf("Zero number\n");
    }
    else
    {
        printf("Negative number\n");
    }
}
#include <stdio.h>
void main()
{
    int a,b,max;
    printf("Enter the numbers\n");
    scanf("%d%d",&a,&b);
    max=a>b?a:b;
    
    printf("Larger number is %d\n",a,b);
}
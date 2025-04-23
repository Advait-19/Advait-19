#include <stdio.h>
void main()
{
    int a,b,c;
    printf("Enter the numbers\n");
    scanf("%d%d",&a,&b);
    c=a;
    a=b;
    b=c;
    
    printf("Swaped values=%d,%d\n",a,b);
}
#include <stdio.h>
void main()
{
    int x,y;
    printf("Enter the numbers\n");
    scanf("%d%d",&x,&y);
    x=x+y;
    y=x-y;
    x=x-y;
    
    printf("Swaped values=%d,%d\n",x,y);
}
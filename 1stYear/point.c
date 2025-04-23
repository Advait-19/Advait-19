#include <stdio.h>
void main()
{
    int x,y;
    printf("Show coordinates\n");
    scanf("%d%d",&x,&y);
    if(x>0&&y>0)
    {
        printf("1st quadrant\n");
    }  
    else if(x<0&&y>0)
    {
        printf("2nd quadrant\n");
    }
    else if(x<0&&y<0)
    {
        printf("3rd quadrant\n");
    }
    else
    {
        printf("4th quadrant\n");
    }
}
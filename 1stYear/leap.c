#include <stdio.h>
void main()
{
    int y;
    printf("Enter the year\n");
    scanf("%d",&y);
    if(y%100 == 0 && y%400!= 0)
    {
        printf("Non-leap year\n");
    }
    else
    {
        printf("Leap year\n");
    }
}
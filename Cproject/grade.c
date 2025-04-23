#include <stdio.h>
void main()
{
    int a;
    printf("Please type your marks\n");
    scanf("%d",&a);
    if(a>=90)
    {
        printf("O grade\n");
    }
    else if(90>a&&a>=70)
    {
        printf("E grade\n");
    }
    else if(70>a&&a>=50)
    {
        printf("A grade\n");
    }
    else 
    {
        printf("FAIL");
    }
}
#include <stdio.h>
void main()
{
    int a;
    printf("Type your number\n");
    scanf("%d",&a);
    if(a%2!=0)
    {
        printf("Number is odd\n");
    }
    else
    {
        printf("Number is even\n");
    }
}
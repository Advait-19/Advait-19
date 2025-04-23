#include <stdio.h>
void main()
{
    int n;
    printf("Enter the numbers\n");
    scanf("%d",&n);

    printf("%s",n%2==0?"even":"odd");

}
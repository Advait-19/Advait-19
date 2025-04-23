#include <stdio.h>
void main()
{
    int a,b,c;
    printf("Enter the numbers\n");
    scanf("%d%d%d",&a,&b,&c);

    printf("Largest number is %d",a>b?a>c?a:c: b>c?b:c);
}
#include <stdio.h>
void main()
{
    int r;
    float area,circum;
    printf("Enter the radius\n");
    scanf("%d",&r);
    area=3.14*r*r;
    circum=2*3.14*r;
    printf("Area=%f\n",area);
    printf("Circumference=%f\n",circum);
}
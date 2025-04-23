#include <stdio.h>
void main()
{
     int u,rate;
     printf("Enter the number of units\n");
     scanf("%d",&u);
     if(u>=0&&u<=50)
     {
        rate=u*2;
        printf("Electric bill=%d\n",rate);
     }
     else if(u>=51&&u<=100)
     {
        rate=100+(u-50)*3;
        printf("Electric bill=%d\n",rate);
     }
     else if(u>=101&&u<=150)
     {
        rate=250+(u-100)*5;
        printf("Electric bill=%d\n",rate);
     }
     else 
     {
        rate=500+(u-150)*10;
        printf("Electric bill=%d\n",rate);
     }
}